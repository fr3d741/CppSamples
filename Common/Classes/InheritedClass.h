#pragma once

#include "BaseClass.h"

class InheritedClass : public BaseClass
{
public:
	virtual char* getName()
	{
		return "InheritedClass";
	}

	char* getFunctionName()
	{
		return __FUNCTION__;
	}
};

