#include <iostream>
#include <string>

#include "fun_with_strings.h"

using namespace std;

int main(void)
{
  string hdr = "Experiment";
  print_header(&hdr, 80);

  string msg_var   = "Hello";
  string *msg_sptr = &msg_var; 
  string *msg_hptr = new string("World");

  cout << *msg_sptr << " " << *msg_hptr << endl;

  cout << "SIZE = " << msg_var.length() << endl;
  cout << "SIZE = " << msg_sptr->length() << endl;
  cout << "SIZE = " << msg_hptr->length() << endl;

  string empty_msg  = "";
  string *empty_ptr = new string("");

  cout << "SIZE = " << empty_msg.length() << endl;
  cout << "SIZE = " << empty_ptr->length() << endl;

  // Bad example 
  print_header(&hdr, 80);

  string *full_msg        = new string("Simon & Garfunkel");
  string pass_as_addr     = "Hello Darkness, my old friend!";
  string pass_as_ref_str  = "I've come to talk to you again!";
  string &pass_as_ref     = pass_as_ref_str;

  // Pass a pointer and change the value of the string pointed to
  // Pass the address of the string pointed to
  // Pass a reference 
  // print_header( full_msg, 80 );
  // print_header( &pass_as_addr, 80 );
  // print_header( &pass_as_ref, 80 );

  cout << endl;
  cout << "msg(*full_msg)       = " << *full_msg       << " at " << full_msg <<endl;
  cout << "msg(pass_as_addr)    = " << pass_as_addr    << " at " << &pass_as_addr <<endl;
  cout << "msg(pass_as_ref_str) = " << pass_as_ref_str << " at " << &pass_as_ref_str <<endl;  

  // print_header( modify_string(full_msg), 80 );
  // print_header( modify_string(&pass_as_addr), 80 );
  // print_header( modify_string(&pass_as_ref), 80 );

  modify_string(full_msg);
  modify_string(&pass_as_addr);
  modify_string(&pass_as_ref);

  cout << endl;
  cout << "msg(*full_msg)       = " << *full_msg       << " at " << full_msg <<endl;
  cout << "msg(pass_as_addr)    = " << pass_as_addr    << " at " << &pass_as_addr <<endl;
  cout << "msg(pass_as_ref_str) = " << pass_as_ref_str << " at " << &pass_as_ref_str <<endl;

  print_header(&hdr, 80);

  reverse_string(full_msg);
  reverse_string(&pass_as_addr);
  reverse_string(&pass_as_ref);

  cout << endl;

  delete msg_hptr;
  delete empty_ptr;
  delete full_msg;

  return 0;
};