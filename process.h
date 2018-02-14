#ifndef PROCESS_H
#define PROCESS_H

/*
container for our processeswith public access by default
 */
#include <iostream>
using namespace std;

struct process{
  int ID;                                                                 
  string state;
  int priority; 
  bool inQueue;
  process* next;//next is included for the case that another process has the same priority number(When a collision occurs in the hashtable)
};


#endif
