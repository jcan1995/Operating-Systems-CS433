output: main.o ReadyQueue.o PCBTable.o
	g++ main.o ReadyQueue.o PCBTable.o -o output

main.o: main.cpp
	g++ -c main.cpp

ReadyQueue.o: ReadyQueue.cpp ReadyQueue.h
	g++ -c ReadyQueue.cpp

PCBTable.o: PCBTable.cpp PCBTable.h
	g++ -c PCBTable.cpp

clean:
	rm *.o output