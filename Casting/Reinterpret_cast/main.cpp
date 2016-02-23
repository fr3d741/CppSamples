#include <iostream>

#include "../../Common/Classes/InheritedClass.h"

using namespace std;

/*
* reinterpret_cast, cast almost anything to anything
*/
int main()
{
	BaseClass bc;
	double d;
	int i = 5;
	char c;
	long long ll;
	char* cp = "Hola!";
	int* ip = &i;
	
	//1) An expression of integral, enumeration, pointer, or pointer - to - member type can be converted to its own type.The resulting value is the same as the value of expression. (since C++11)
	{
		//int ii = reinterpret_cast<int>(45);
		char* cp_l = reinterpret_cast<char*>(cp);
	}

	//2) Any pointer can be converted to any integral type large enough to hold the value of the pointer(e.g.to std::uintptr_t)
	{
		i = reinterpret_cast<int>(&bc);
		int* iip = reinterpret_cast<int*>(&bc);
		cp = reinterpret_cast<char*>(&d);

		short s = reinterpret_cast<short>(ip);
		int ptr = reinterpret_cast<int>(ip);
		long long lptr = reinterpret_cast<long long>(ip);
		cout << hex << ip << endl;
		cout << hex << ptr << endl;
		cout << hex << s << endl;
		cout << hex << lptr << endl;
	}
	//3) A value of any integral or enumeration type can be converted to a pointer type.A pointer converted to an integer of sufficient size and back to the same pointer type is guaranteed to have its original value, otherwise the resulting pointer cannot be dereferenced safely(the round - trip conversion in the opposite direction is not guaranteed; the same pointer may have multiple integer representations) The null pointer constant NULL or integer zero is not guaranteed to yield the null pointer value of the target type; static_cast or implicit conversion should be used for this purpose.
	{

	}
	//4) Any value of type std::nullptr_t, including nullptr can be converted to any integral type as if it were(void*)0, but no value, not even nullptr can be converted to std::nullptr_t: static_cast should be used for that purpose. (since C++11)
	//5) Any pointer to object of type T1 can be converted to pointer to object of another type cv T2.This is exactly equivalent to static_cast<cv T2*>(static_cast<cv void*>(expression)) (which implies that if T2's alignment requirement is not stricter than T1's, the value of the pointer does not change and conversion of the resulting pointer back to its original type yields the original value).In any case, the resulting pointer may only be dereferenced safely if allowed by the type aliasing rules(see below)
	//6) An lvalue expression of type T1 can be converted to reference to another type T2.The result is an lvalue or xvalue referring to the same object as the original lvalue, but with a different type.No temporary is created, no copy is made, no constructors or conversion functions are called.The resulting reference can only be accessed safely if allowed by the type aliasing rules(see below)
	//7) Any pointer to function can be converted to a pointer to a different function type.Calling the function through a pointer to a different function type is undefined, but converting such pointer back to pointer to the original function type yields the pointer to the original function.
	//8) On some implementations(in particular, on any POSIX compatible system as required by dlsym), a function pointer can be converted to void* or any another object pointer, or vice versa.If the implementation supports conversion in both directions, conversion to the original type yields the original value, otherwise the resulting pointer cannot be dereferenced or called safely.
	//9) The null pointer value of any pointer type can be converted to any other pointer type, resulting in the null pointer value of that type.Note that the null pointer constant nullptr or any other value of type std::nullptr_t cannot be converted to a pointer with reinterpret_cast: implicit conversion or static_cast should be used for this purpose.
	//10) An rvalue pointer to member function can be converted to pointer to a different member function of a different type.Conversion to the original type yields the original value, otherwise the resulting pointer cannot be used safely.
	//11) An rvalue pointer to member object of some class T1 can be converted to a pointer to another member object of another class T2.If T2's alignment is not stricter than T1's, conversion to the original type yields the original value, otherwise the resulting pointer cannot be used safely.

	getchar();
	return 1;
}