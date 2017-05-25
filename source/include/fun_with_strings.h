#ifndef __FUN_WITH_STRINGS_H__ 
#define __FUN_WITH_STRINGS_H__

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void print_border (char line_char, char end_char, unsigned line_width)
{
	cout << end_char;
	for (int i = 0; i < line_width-2; i++) { cout << line_char; };
	cout << end_char << endl;
};

void print_padding (unsigned text_length, unsigned line_width)
{
	for (int i = 0; i < (line_width-4)-text_length; i++) { cout << " "; };
};

void print_header (string *text, unsigned line_width)
{
	unsigned num_of_lines;
	unsigned length = text->length();

	if ( length <= 0 	)	{ cout << "Empty or Invalid string passed as an argument." << endl;  return; } 
	if ( line_width < 3 )	{ cout << "Minimum line_width = 3." << endl;  return; }

	// If text fits within a single line
	if ( length <= line_width-4 ) 
	{
		cout << endl;
		print_border('=', '+', line_width);
		cout << "| " << *text;
		print_padding(length, line_width);
		cout << " |" << endl;
		print_border('=', '+', line_width);
		cout << endl;		
	};
};

string *modify_string (string *text)
{
	*text = "Hacked!";

	return text;
};


string *reverse_string (string *text)
{
	unsigned length = text->length();
	
	if ( length <= 0) {cout << "Empty String" << endl; return NULL;};

	string temp_arg = *text;
	char temp_res[length];

	cout << "SIZE = " << length << endl;

	for (int i = 0; i < length; i++ ) 
	{
		cout << "index = " << (length-1)-i << " value = " << temp_arg[(length-1)-i] << endl;
		temp_res[i] = temp_arg[(length-1)-i];
	};

	cout << "Original String = " << temp_arg << endl;
	cout << "Resersed String = " << temp_res << endl;

	*text = temp_res;

	return text;
};

// +========================+
// | the brown fox is here. |
// +========================+

#endif