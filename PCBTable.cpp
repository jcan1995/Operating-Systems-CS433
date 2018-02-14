#include <ctime>
#include "PCBTable.h"
#include <vector>
#include <stdlib.h>
using namespace std;

PCBTable::PCBTable(){

  srand(time(NULL));
  /*Initialize our PCBTable in our constructor. Set a random priority in each iteration.
   
   */
  for(int i = 0; i < 20; i++){    
    
    process *p = new process;
    p -> ID = i;
    p -> priority = (rand() % 50);
    p -> inQueue = false;
    p -> state = "NEW";
    p -> next = NULL;
    table.push_back(p);

  }

}

//Returns a process pointer first setting its state to READY. This is called when adding it to our Queue.
process* PCBTable::getProcess(){
  for(int i = 0; i < table.size();i++){
    if(table[i] -> state == "NEW"){
      table[i] -> state = "READY";
      return table[i];
    }

  }
  return NULL;
}
//Iterate across the vector until we find the specified process, then return it. Else return NULL
process* PCBTable::getProcess(int id){
  for(int i = 0; i < table.size();i++){
    if(table[i] -> ID == id){
      return table[i];

    }
  }
  return NULL;
}
