#ifndef SIMPLE_TOOLS_H
#define SIMPLE_TOOLS_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void print_msg (string *text)
{
	cout << ">> " << *text << endl;
};

string reverse_msg_and_return_as_string (string *text)
{
	string rev_str = "dummy";

	int msg_size = sizeof(*text);

	if (msg_size <= 0) 
	{
		return ">> Empty string passed";
	}

	return rev_str;

	// for (int i = 0; i < print_msg; ++i)
	// {
		
	// }

	// cout << ">> " << *text << endl;
};

#endif
