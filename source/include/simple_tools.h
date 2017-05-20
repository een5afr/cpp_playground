#ifndef SIMPLE_TOOLS_H
#define SIMPLE_TOOLS_H

#include <iostream>
#include <iomanip>
#include <string>

//using namespace std;

void print_msg (std::string *text)
{
	std::cout << ">> " << *text << std::endl;

	*text = "Hacked";

	std::cout << ">> " << *text << std::endl;
};

#endif
