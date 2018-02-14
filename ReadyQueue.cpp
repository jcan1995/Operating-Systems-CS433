#include "ReadyQueue.h"
#include <iostream>

//Create a default array of process pointers. Building our Hashtable here
ReadyQueue::ReadyQueue(){

  for(int i = 0; i < tableSize;i++){
    hashTable[i] = new process;
    hashTable[i] -> ID = 0;
    hashTable[i] -> state = "NONE";
    hashTable[i] -> inQueue = false;
    hashTable[i] -> next = NULL;
    hashTable[i] -> priority = 0;
  }

}

int ReadyQueue::hash(int priority){
  int index = priority; //Separate each process by their priorities...
  return index;
}

void ReadyQueue::insertProc(process* p){//insert the processes based on their priority level

  if(p == NULL){
    return;
  }

  int index = hash(p -> priority);
  //If there is currently noprocess occupying this index, fill it with the new process
  if(hashTable[index] -> state == "NONE"){
    
    p -> state = "READY";
    p -> inQueue = true;
    hashTable[index] = p;
    count++;
    return;
  }else{//Else a collision occurred, thus we start a linked list in the index.
    
    p -> next = hashTable[index];
    p -> state = "READY";                                                                                                                                                 
    p -> inQueue = true;   
    hashTable[index] = p;
    count++;
    return;
    /*  
    process *ptr = hashTable[index];
    p -> state = "READY";
    p -> inQueue = true;
    while(ptr -> next != NULL){
      ptr = ptr -> next;
      
    }
    //Insert the process at the end of the linkedlist in its' respective index.
    ptr -> next = p;
    p -> next = NULL;
*/
    //count++;
  }
}

int ReadyQueue::getCount(){
  return count;
}

//Returns the count of a spefied index
int ReadyQueue::sizeInIndex(int index){

  int count = 0;
  if(hashTable[index] -> state == "NONE")
    return count;
  else{
    process* ptr = hashTable[index];
    while(ptr != NULL){
      count++;
      ptr = ptr -> next;
    
    }
  }
  return count;

}
//Iterates over our hashtable, calling "sizeInIndex(int)" aggregating the count. N^2 solution
/*int ReadyQueue::size(){
  int count = 0;
  for(int i = 0; i <tableSize;i++){
    count += sizeInIndex(i);
  }
  return count;

}

*/
process* ReadyQueue:: removeHighestProc(){

  if(count == 0)
    return NULL;

  for(int i = 0; i <tableSize;i++){
    if(hashTable[i] -> state == "READY"){
      process* node = hashTable[i];
      node -> state = "RUNNING";
      if(hashTable[i] -> next == NULL){
        hashTable[i] = new process;
        hashTable[i] -> ID = 0;
        hashTable[i] -> state = "NONE";
        hashTable[i] -> inQueue = false;
        hashTable[i] -> next = NULL;

      }
      else
        hashTable[i] = node -> next;
      node -> inQueue = false;
      count--;
      return node;
    }
  }
  
  return NULL;//There is nothing in the list.
}


void ReadyQueue:: displayQueue(){
  cout<<"------------QUEUE------------"<<endl;
  for(int i = 0; i < tableSize; i++){
    process *p = hashTable[i];
    cout<<"ID:"<< p -> ID<<endl;
    cout<<"State:"<< p -> state<<endl;
    cout<<"Priority:"<< p -> priority<<endl;
    cout<<"Inqueue?: "<< p -> inQueue<<endl;
    p = p -> next;
    while(p != NULL){
      cout<<"   |"<<endl;
      cout<<"   |"<<endl;
      cout<<"   |"<<endl;
      cout<<"   |"<<endl;

      cout<<"ID:"<< p -> ID<<endl;
      cout<<"State:"<< p -> state<<endl;
      cout<<"Priority:"<< p -> priority<<endl;
      cout<<"Inqueue?: "<< p -> inQueue<<endl;
      p = p -> next;
    }
    cout<<endl;
  }
  cout<<"------------END QUEUE------------"<<endl;

}






