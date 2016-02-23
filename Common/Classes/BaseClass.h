#pragma once

class BaseClass
{
public:
	virtual char* getName()
	{
		return "BaseClass";
	}

	char* getFunctionName()
	{
		return __FUNCTION__;
	}
};

