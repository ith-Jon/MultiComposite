#pragma once
#include "IpcTools.h"

struct CStaticEmptyDescriptor
{
	SECURITY_ATTRIBUTES secAttr;
	char secDesc[SECURITY_DESCRIPTOR_MIN_LENGTH];

	static void GetSidForProcess(HANDLE pid, PSID* pSid)
	{
		HANDLE hToken = NULL;

		if (OpenProcessToken(pid, TOKEN_QUERY, &hToken) == FALSE)
		{
			DWORD dwErrorCode = GetLastError();
			dlog::Println("OpenProcessToken failed. GetLastError returned: " + dwErrorCode);
		}
		else
		{
			DWORD dwBufferSize = 0;

			GetTokenInformation(hToken, TokenUser, NULL, 0, &dwBufferSize);

			PTOKEN_USER  pTokenUser = (PTOKEN_USER) new BYTE[dwBufferSize];
			memset(pTokenUser, 0, dwBufferSize);
			if (GetTokenInformation(hToken, TokenUser, pTokenUser, dwBufferSize, &dwBufferSize) == FALSE)
			{
				DWORD dwErrorCode = GetLastError();
				dlog::Println("GetTokenInformation failed. GetLastError returned: " + dwErrorCode);
			}

			CloseHandle(hToken);

			if (IsValidSid(pTokenUser->User.Sid) == FALSE)
			{
				dlog::Println("The owner SID is invalid.\n");
			}
			else
			{
				DWORD nBytesSide = GetLengthSid(pTokenUser->User.Sid);
				*pSid = new BYTE[nBytesSide];
				CopySid(nBytesSide, *pSid, pTokenUser->User.Sid);
			}

			delete[] pTokenUser;
		}
	}

	static unsigned int GetRegistryUint(const char* pchKeyName, const char* pchValueName)
	{
		HKEY hKey = NULL;
		DWORD dwValue = 0;
		unsigned int uRet = ::RegOpenKeyA(HKEY_CURRENT_USER, pchKeyName, &hKey);
		if (ERROR_SUCCESS == uRet)
		{
			DWORD dwType;
			DWORD dwLen = sizeof(dwValue);
			uRet = ::RegQueryValueExA(hKey, pchValueName, NULL, &dwType, (LPBYTE)&dwValue, (LPDWORD)&dwLen);
			RegCloseKey(hKey);
		}

		return dwValue;
	}

	CStaticEmptyDescriptor()
	{
		m_pDACL = NULL;

		secAttr.nLength = sizeof(secAttr);
		secAttr.bInheritHandle = FALSE;
		secAttr.lpSecurityDescriptor = &secDesc;
		if (InitializeSecurityDescriptor(secAttr.lpSecurityDescriptor, SECURITY_DESCRIPTOR_REVISION) == TRUE)
		{
			PSID psidUserSid = NULL;
			PSID psidSteamSid = NULL;
			PSID psidAdministratorGroupSid = NULL;
			const int nSIDS = 3;

			GetSidForProcess(GetCurrentProcess(), &psidUserSid);

			DWORD dwProcessId = GetRegistryUint("Software\\Valve\\Steam\\ActiveProcess", "pid");

			HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION, false, dwProcessId);
			if (hProcess)
			{
				GetSidForProcess(hProcess, &psidSteamSid);
				CloseHandle(hProcess);
			}

			DWORD cbSidSize = SECURITY_MAX_SID_SIZE;
			psidAdministratorGroupSid = new BYTE[cbSidSize];
			CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, psidAdministratorGroupSid, &cbSidSize);

			int cbDacl = sizeof(ACL) + sizeof(ACCESS_ALLOWED_ACE) * nSIDS;
			if (psidUserSid)
				cbDacl += GetLengthSid(psidUserSid);
			if (psidAdministratorGroupSid)
				cbDacl += GetLengthSid(psidAdministratorGroupSid);
			if (psidSteamSid)
				cbDacl += GetLengthSid(psidSteamSid);

#ifdef _SERVER
			m_pDACL = (PACL)PvAllocNoLeakTracking(cbDacl);
#else
			m_pDACL = (PACL) new BYTE[cbDacl];
#endif
			if (m_pDACL)
			{
				memset(m_pDACL, 0, cbDacl);

				if (InitializeAcl(m_pDACL, cbDacl, ACL_REVISION) == FALSE)
				{
					DWORD dwErrorCode = GetLastError();
					dlog::Println("InitializeAcl failed. GetLastError returned: " + dwErrorCode);

					delete[] m_pDACL;
					m_pDACL = NULL;
				}
				else
				{
					if (psidUserSid && AddAccessAllowedAce(m_pDACL, ACL_REVISION, GENERIC_ALL, psidUserSid) == FALSE)
					{
						DWORD dwErrorCode = GetLastError();
						dlog::Println("AddAccessAllowedAce failed for the process owner. GetLastError returned: " + dwErrorCode);
					}

					if (psidAdministratorGroupSid && AddAccessAllowedAce(m_pDACL, ACL_REVISION, GENERIC_ALL, psidAdministratorGroupSid) == FALSE)
					{
						DWORD dwErrorCode = GetLastError();
						dlog::Println("AddAccessAllowedAce failed for administrator. GetLastError returned: " + dwErrorCode);
					}

					if (psidSteamSid && AddAccessAllowedAce(m_pDACL, ACL_REVISION, GENERIC_ALL, psidSteamSid) == FALSE)
					{
						DWORD dwErrorCode = GetLastError();
						dlog::Println("AddAccessAllowedAce failed for steam. GetLastError returned: " + dwErrorCode);
					}

					if (SetSecurityDescriptorDacl(secAttr.lpSecurityDescriptor, TRUE, m_pDACL, FALSE) == FALSE)
					{
						DWORD dwErrorCode = GetLastError();
						dlog::Println("SetSecurityDescriptorDacl failed. GetLastError returned: " + dwErrorCode);
					}
				}

				delete[] psidUserSid;
				delete[] psidAdministratorGroupSid;
				delete[] psidSteamSid;
			}
		}
		else
		{
			DWORD dwErrorCode = GetLastError();
			dlog::Println("InitializeSecurityDescriptor failed. GetLastError returned: " + dwErrorCode);
		}
	}

	~CStaticEmptyDescriptor()
	{
		if (m_pDACL)
		{
#ifdef _SERVER
			FreePv(m_pDACL);
#else
			delete[] m_pDACL;
#endif
			m_pDACL = NULL;
		}
	}

private:
	PACL m_pDACL;
};

static LPSECURITY_ATTRIBUTES GetEmptySecurityAttrs()
{
	static CStaticEmptyDescriptor s_emptySecurity;
	return &s_emptySecurity.secAttr;
}

class Win32SharedMemory : public ISharedMem
{
public:
	Win32SharedMemory()
	{
		hMapFile = NULL;
		pData = NULL;
	}

	~Win32SharedMemory()
	{
		Destroy();
	}

	void* Pointer() const
	{
		return pData;
	}

	void Destroy()
	{
		if (pData)
			UnmapViewOfFile(pData);

		if (hMapFile)
			CloseHandle(hMapFile);

		hMapFile = pData = NULL;
	}

	bool Init(const char* name, uint32_t size, ISharedMem::Role role)
	{
		std::string newName = "MultiComposite//";
		newName += name;

		if (role == ISharedMem::Client)
		{
			dlog::Println("Openning file mapping of " + newName);

			
		}
		else
		{
			dlog::Println("Creating file mapping of " + newName);

			
		}

		dlog::Println("Creating file mapping of " + newName);
		hMapFile = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, size, newName.c_str());
		if (hMapFile == NULL || hMapFile == INVALID_HANDLE_VALUE)
		{
			hMapFile = NULL;
			DWORD dwErrorCode = GetLastError();
			dlog::Println("Failed creating file mapping " + newName + ". GetLastError returned: " + std::to_string(dwErrorCode));

			hMapFile = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, newName.c_str());
			if (hMapFile == NULL || hMapFile == INVALID_HANDLE_VALUE)
			{
				hMapFile = NULL;
				DWORD dwErrorCode = GetLastError();
				dlog::Println("Failed openning file mapping " + newName + ". GetLastError returned: " + std::to_string(dwErrorCode));
				return false;
			}
		}

		dlog::Println("Mapping file view of " + newName);
		pData = MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, size);
		if (pData == NULL)
		{
			DWORD dwErrorCode = GetLastError();
			dlog::Println("Failed mapping view of file for " + newName + ". GetLastError returned: " + std::to_string(dwErrorCode));
			CloseHandle(hMapFile);
			hMapFile = NULL;
			return false;
		}

		return true;
	}
private:
	HANDLE hMapFile;
	void* pData;
};