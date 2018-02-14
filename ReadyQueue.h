#ifndef READYQUEUE_H
#define READYQUEUE_H

#include "process.h"
class ReadyQueue{
  
 private:
  //  int highestPriority = 100;
  static const int tableSize = 50;
  int count = 0;  
  process* hashTable[tableSize];



 public:
  ReadyQueue();
  int hash(int priority);
  void insertProc(process*);//In this function adjust the priority variables as we insert
  int sizeInIndex(int);
  process* removeHighestProc();
  //  int size();//Iterate over array while calling "sizeInIndex" size+=sizeInIndex(i);
  void displayQueue();  
  int getCount();

 
};
#endif
