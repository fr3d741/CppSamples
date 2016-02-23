#include <iostream>
#include <assert.h>

using namespace std;

int gi = 1;
const int cgi = 2;

/*
* const_cast is for cast away const from pointers, and references. 
*/
int main()
{
	int i = 3;
	const int ci = 4;
	const int* ci_ptr = &ci;

	*const_cast<int*>(ci_ptr) = 111;
	const_cast<int&>(ci) = 112;
	assert(ci == 4);					//changing const is not possible
	const int* c_ptr_i = &i;
	*const_cast<int*>(c_ptr_i) = 113;	//cast away const from pointer, that's ok
	assert(i == 113);
	int* ptr = const_cast<int*>(&cgi);	//compiler allows it
	//*ptr = 114;						//but writing causes access violation

	return 1;
}