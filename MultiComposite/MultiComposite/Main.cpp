#include "MultiComposite.h"
#include "strtools_public.h"
#include "openvr.h"

#include "Compositor.h"

#include <iostream>
#include <Windows.h>
#include <ShlObj_core.h>
#include <time.h>

int main()
{
	std::string title = "[MultiComposite]";
	SetConsoleTitleA(title.c_str());

	// TODO: Grab Config File

	// TODO: Grab SteamVR Dir From Config File

	// TODO: Check if to start MultiComposite or set OpenVR config file to point to the actual SteamVR Installation

	std::cout << "Starting MultiComposite..." << "\n";

	MultiComposite mComposite = MultiComposite();
	mComposite.Init();

	// TODO: Set OpenVR Config File To Point To This Dir

	std::cout << "Setting up D3D11 Backend..." << "\n";
	ICompositor::pD11Compositor = new D3D11Compositor();
	ICompositor::pD11Compositor->Init();

	std::cout << "MultiComposite Ready." << "\n";

	while (mComposite.running)
	{
		mComposite.Update();
		mComposite.WaitGetPoses();
		mComposite.Render();
	}

	return 0;
}
