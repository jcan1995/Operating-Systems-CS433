#ifndef PCBTABLE_H
#define PCBTABLE_H

#include "process.h"
#include <vector>
using namespace std;

class PCBTable{
private:
  vector<process*> table;//For our PCBTable we use a vector containing process pointers 

public:
  PCBTable();//Initialize the table  
  process* getProcess();//Get the process with the highest priority
  process* getProcess(int id);//Get a process by id
};
#endif
