#include <assert.h>
#include <iostream>

#include "InheritedClass.h"

using namespace std;

int main()
{
	BaseClass* bc = new BaseClass;
	InheritedClass* ic = new InheritedClass;

	cout << bc->getName() << endl;
	cout << bc->getFunctionName() << endl;
	cout << ic->getName() << endl;
	cout << ic->getFunctionName() << endl;

	//Now the tricky parts
	InheritedClass* fault_ic = dynamic_cast<InheritedClass*>(bc);
	assert(fault_ic == nullptr);								// BaseClass is not InheritedClass
	BaseClass* bc_ptr = dynamic_cast<BaseClass*>(ic);
	assert(bc_ptr != nullptr);									// InheritedClass is BaseClass
	assert(bc_ptr->getName() == ic->getName());					//because of virtual getName still calls the child object
	assert(bc_ptr->getFunctionName() != ic->getFunctionName()); //but getFunctionName is not virtual

	getchar();
	return 1;
}

