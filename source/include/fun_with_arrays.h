#ifndef __FUN_WITH_ARRAYS_H__ 
#define __FUN_WITH_ARRAYS_H__

#include <iostream>
#include <string>
#include <sstream>  // Required for stringstreams
#include <cstring>

using namespace std;

template <typename T>
string NumberToString ( T Number )
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}

string *create_array_of_string( unsigned size )
{
	string *str_array = new string[size];

	for (int i = 0; i < size; i++)
	{
		str_array[i] = "fun_with_num_"+NumberToString(i);
	};

	return str_array;
};

int return_first_matched( const string *str_array, string pattern, unsigned size )
{
	for (int i = 0; i < size; i++)
	{
		if (*(str_array+i) == pattern) 
		{
			return i;
		};
	};

	return -1;
};

string *duplicate_array( const string *str_array, unsigned size )
{
	string *cpy_array = new string[size];

	for (int i = 0; i < size; i++)
	{
		cout << "*str_array[" << i << "] = " << str_array[i] << " at addr = " << &(str_array[i]) << endl;

		cpy_array[i] = str_array[i];
		
		cout << "*cpy_array[" << i << "] = " << str_array[i] << " at addr = " << &(cpy_array[i]) << endl;
	};

	return cpy_array;
};

string *delete_array ( string *str_array )
{
	cout << "Array at " << str_array << " deleted." << endl;
	delete str_array;
};

#endif //__FUN_WITH_ARRAYS_H__