#include <iostream>
#include <string>

#include "fun_with_arrays.h"

using namespace std;

void fun_with_arrays(void)
{
	string *array_ptr = create_array_of_string( 10 );
	
	cout << "sizeof(array_ptr) returns size of pointer \t: "    << sizeof(array_ptr)  << endl;
	cout << "sizeof(array_ptr) returns size of each entry \t: " << sizeof(*array_ptr) << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "i = " << i <<" , Array at " << array_ptr << " containing " << *array_ptr << endl;
		array_ptr++;
	}

	return;
};

