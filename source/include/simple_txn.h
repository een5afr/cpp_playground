#ifndef SIMPLE_TXN_H
#define SIMPLE_TXN_H

#include <iostream>
#include <iomanip>

// using namespace std;

//typedef unsigned long long uint64_t;
typedef enum {READ, WRITE} cmd_t;

struct simple_txn
{
	unsigned id;
	uint64_t addr;
	unsigned size;
	cmd_t    type;
};

bool is_power_of_two (unsigned bus_bytes)
{
	std::cout << "Checking power of 2 ..." << std::endl;
	return (bus_bytes != 0 && !(bus_bytes & bus_bytes-1));
};

bool is_burst_legal (simple_txn *txn, unsigned page_size)
{
	unsigned floor = txn->addr & ~(page_size-1);
	unsigned ceil  = floor | (page_size-1);

  std::cout << "floor = 0x" << std::hex << floor << ", ceil = 0x" << std::hex << ceil << std::endl;

	return ((txn->addr+txn->size) <= ceil);
};

bool is_addr_aligned (simple_txn *txn, unsigned bus_bytes)
{
	unsigned word_offset = txn->addr & (bus_bytes-1);

  std::cout << "word_offset = 0x" << std::hex << word_offset << std::endl;

	return (word_offset == 0);
};

bool is_burst (simple_txn *txn, unsigned bus_bytes)
{
	return !(txn->size == bus_bytes);
};

bool sanity_check(simple_txn *txn, unsigned bus_bytes, unsigned page_size)
{
	return ( is_addr_aligned(txn, bus_bytes) &&
					 is_burst_legal(txn, page_size)  &&
           is_power_of_two(bus_bytes));
};

void print_txn(simple_txn *txn)
{
	std::cout << "ID   : 0x" << std::hex << txn->id   << std::endl;
	std::cout << "ADDR : 0x" << std::hex << txn->addr << std::endl;
	std::cout << "SIZE : 0x" << std::hex << txn->size << std::endl;
	std::cout << "TYPE : 0x" << std::hex << txn->type << std::endl;
};

void align_addr_to_bus_bytes(simple_txn &txn, unsigned bus_bytes)
{
};

void align_burst_to_page_size(simple_txn &txn, unsigned page_size)
{
};

#endif
