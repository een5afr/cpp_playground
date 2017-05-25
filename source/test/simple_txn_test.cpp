#include <iostream>
#include <string>
#include "simple_txn.h"
#include "simple_tools.h"

//using namespace std;

int main(void)
{
  simple_txn *a_txn = new simple_txn;

  unsigned bus_bytes = 4;
  unsigned page_size = 4096;

  a_txn->id   = 0;
  a_txn->addr = 0xffff0000;
  a_txn->size = 64;
  a_txn->type = READ;

  print_txn(a_txn);

  bool test0 = is_power_of_two(bus_bytes);
	bool test1 = is_addr_aligned(a_txn, bus_bytes);
	bool test2 = is_burst_legal(a_txn, page_size);
	bool test3 = sanity_check(a_txn, bus_bytes, page_size);

	std::string pass_msg = "Test Passed";
	std::string fail_msg = "Test Failed";
  std::string *ptr_msg = &pass_msg;

  if ( test0 ) { print_msg(ptr_msg);   };
  else { std::string *ptr_msg = &fail_msg; print_msg(fail_msg); }

	std::cout << pass_msg << std::endl;

  return 0;
};
