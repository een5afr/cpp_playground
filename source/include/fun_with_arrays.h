#ifndef __FUN_WITH_ARRAYS_H__ 
#define __FUN_WITH_ARRAYS_H__

#include <iostream>
#include <string>
#include <sstream>  // Required for stringstreams

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

string *search_array_by_string( string pattern )
{



};

string *search_array_by_index( unsigned index )
{

};

string *duplicate_array(  )
{

};

string *delete_array ( string *str_array )
{
	cout << "Array at " << str_array << " deleted." << endl;
	delete str_array;
};

#endif //__FUN_WITH_ARRAYS_H__