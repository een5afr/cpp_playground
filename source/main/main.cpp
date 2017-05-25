#include <iostream>
#include <string>

using namespace std;

void fun_with_strings();
void fun_with_arrays();

int main(int argc, char *argv[])
{
	cout << "\n Num of Arguments : " << argc << endl;

	for (int i = 1; i < argc; i++)
 	{	
 		if 		(argv[i] == string("-strings"))	{ fun_with_strings();}
 		else if (argv[i] == string("-arrays"))	{ fun_with_arrays(); }
 		else if (argv[i] == string("-help"))  	{ cout << "\n Valid Switches : -arrays -strings" << endl; }
 		else 									{ cout << "\n Incorrect Argument : " << argv[i] << endl; };
 	};

 	cout << endl;

	return 0;
};
