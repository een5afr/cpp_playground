#include <iostream>
#include <string>

#include "fun_with_arrays.h"

using namespace std;

void fun_with_arrays(void)
{
	unsigned size(10);
	string *array_ptr = create_array_of_string( size );
	
	cout << "\nsizeof(array_ptr) returns size of pointer \t: "  << sizeof(array_ptr)  << endl;
	cout << "sizeof(*array_ptr) returns size of each entry \t: " << sizeof(*array_ptr) << endl;
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "i = " << i << ", &array_ptr[i] = " << &array_ptr[i] << " contains " << array_ptr[i] <<endl;
		if (i == size-1) { cout << endl; };
	};

	for (int i = 0; i < size; i++)
	{
		cout << "i = " << i << ", (array_ptr+i) = " << (array_ptr+i) << " contains " << *(array_ptr+i) <<endl;
		if (i == size-1) { cout << endl; };
	};

	int i =  return_first_matched( array_ptr, "fun_with_num_2", size );

	if ( i >= 0 ) { cout << "\nIndex = " << i << ", Address = " << (array_ptr+i) << ", Text = " << *(array_ptr+i) << endl; }
	else		  { cout << "\nNot Found !!!" << endl; }; 

	string *copy_ptr = duplicate_array( array_ptr, 10 );
	cout << endl;
	string  copy_str = *duplicate_array( array_ptr, 10 );

	return;
};
