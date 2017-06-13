#ifndef __FUN_WITH_LINKED_LISTS_H__ 
#define __FUN_WITH_LINKED_LISTS_H__

#include <iostream>
#include <string>
#include <sstream>  // Required for stringstreams
//#include <cstring>

using namespace std;

typedef struct {

	unsigned id;
	unsigned value;

	simple_node_t *next;
	simple_node_t *prev;

} simple_node_t;

#endif //__FUN_WITH_LINKED_LISTS_H__