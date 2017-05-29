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

void print_msgbox (string *text, unsigned line_width)
{
	unsigned size 	= (text->length())+1;
	char *temp_char	= const_cast<char*>(text->c_str());;

	//
	bool perfect_fit  	= (size % (line_width-4) == 0); 

	int num_of_lines 	= perfect_fit ?	(size/(line_width-4)) : 
										(size/(line_width-4))+1;
	
	// for (int i = 0; i < size; i++)
	// {
	// 	if (temp_char[i] == '\0') { cout << "*"; };
	// 	cout << temp_char[i];
	// }

	//cout << "size, perfect_fit, num_of_lines, residue = " << size << " " << perfect_fit << " " << num_of_lines << " " << size % (line_width-2) << endl; 
	cout << endl;
	print_border('-', '+', line_width);

	for (int row = 0; row < num_of_lines; row++)
	{
		bool row_last 	= ( row == num_of_lines-1 );
		
		int  col_width	= 	perfect_fit ? line_width-4 : 
							row_last 	? size % (line_width-4) : line_width-4;

		for (int col = 0; col < line_width-4; col++)
		{
			if ( col == 0 ) { cout << "| "; };

			bool add_padding = row_last && (col == col_width); 
			bool ignore_char = temp_char[row*(line_width-4)+col] == '\0';

			if ( add_padding || ignore_char ) 	{ cout << " "; }
			else 								{ cout << temp_char[row*(line_width-4)+col]; };

			if ( col == line_width-5 ) { cout << " |" << endl; };
		};
	};

	print_border('-', '+', line_width);

	return;
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