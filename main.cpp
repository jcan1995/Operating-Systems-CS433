#include <chrono>
#include <iomanip>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include "PCBTable.h"
#include "ReadyQueue.h"
using namespace std;
const int iterations = 1000000;


int probability(){
  return rand() % 2 + 1;//Between 2 and 1
}

//Test 1 from PDF
void test1(){

  cout<<"-------------------TEST 1-------------------"<<endl;
  PCBTable table;
  ReadyQueue q1;
  q1.insertProc(table.getProcess(5));
  q1.insertProc(table.getProcess(1));
  q1.insertProc(table.getProcess(8));
  q1.insertProc(table.getProcess(11));
  q1.insertProc(table.getProcess(50));
  q1.displayQueue();
  process *p = q1.removeHighestProc();
  
  cout<<"------------PROCESS REMOVED FROM QUEUE------------"<<endl;
  cout<<"ID: "<<p -> ID<<endl;
  cout<<"State: "<<p -> state<<endl;
  cout<<"Priority: "<<p -> priority<<endl;
  cout<<"inQueue?: "<<p -> inQueue<<endl;
  cout<<"------------PROCESS REMOVED FROM QUEUE------------"<<endl;
  
  q1.displayQueue();
  p = q1.removeHighestProc();
  cout<<"------------PROCESS REMOVED FROM QUEUE------------"<<endl;
  cout<<"ID: "<<p -> ID<<endl;
  cout<<"State: "<<p -> state<<endl;
  cout<<"Priority: "<<p -> priority<<endl;
  cout<<"inQueue?: "<<p -> inQueue<<endl;
  cout<<"------------PROCESS REMOVED FROM QUEUE------------"<<endl;
  
  q1.displayQueue();
  q1.insertProc(table.getProcess(3));
  q1.insertProc(table.getProcess(7));
  q1.insertProc(table.getProcess(2));
  q1.insertProc(table.getProcess(12));
  q1.insertProc(table.getProcess(9));
  while(q1.getCount() != 0){
    p = q1.removeHighestProc();
    cout<<"------------PROCESS REMOVED FROM QUEUE------------"<<endl;
    cout<<"ID: "<<p -> ID<<endl;
    cout<<"State: "<<p -> state<<endl;
    cout<<"Priority: "<<p -> priority<<endl;
    cout<<"inQueue?: "<<p -> inQueue<<endl;
    cout<<"------------PROCESS REMOVED FROM QUEUE------------"<<endl;
  }      
  cout<<"-------------------TEST 1-------------------"<<endl;

}

void test2(){
  cout<<"-------------------TEST 2-------------------"<<endl;
                                                                                                              
  int removed = 0;                                                                                              
  int added = 0;                                                                                                
  PCBTable table;                                                                                               
  ReadyQueue q;                                                                                                 
                                                                                                                
  //  auto start = std::chrono::system_clock::now();                                                                
  srand(time(NULL));
  auto start = std::chrono::system_clock::now();                                                                                                                                
  for(int i = 0; i < iterations;i++){                                                                           
    //    if(rand() % 2 == 1){                                                                                     
    if(rand() % 2 == 1){

      removed++;                                                                                                
      q.removeHighestProc();                                                                                    
    }                                                                                                           
    else{                                                                                                       
      process *p = table.getProcess();                                                                          
      //      if(p == NULL)                                                                                     
      //break;                                                                                          
      //      else                                                                                              
      added++;                                                                                                  
      if(p!= NULL)                                                                                              
        q.insertProc(p);//Insert from PCBTable unless they're already added TODO                                
                                                                                                                
    }                                         
}                                                                                                           
  auto end = std::chrono::system_clock::now();                                                                  
  std::chrono::duration<double> elapsed_seconds = end - start;                                                  
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";                                            
  
  cout<<"after loop"<<endl;                                                                                     
                                                                                                                
  cout<<endl;                                                                                                   
  cout<<endl;                                                                                                   
  cout<<endl;                                                                                                   
  cout<<endl;                                                                                                   
                                                                                                                
  q.displayQueue();                                                                                             
  cout<<"SIZE: "<<q.getCount()<<endl;                                                                               
  cout<<"added: "<<added<<endl;                                                                                 
  cout<<"removed: "<<removed<<endl;                                                                             
  

  cout<<"-------------------TEST 2-------------------"<<endl;

}

int main(){
  cout<<"JOSHUA CANTERO"<<endl;
  test1();
  test2();
  return 0;

}
