#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Logger.h"

#define CREATE_OBJECT( TYPE, ... )		\
	TYPE *pObj = new TYPE();			\
	if ( !pObj->Init( __VA_ARGS__ ) )	\
	{									\
		delete pObj;					\
		return NULL;					\
	}									\
	return pObj;

class ISharedMem
{
public:
	enum Role
	{
		Server,
		Client,
	};

	virtual void* Pointer() const = 0;
};
