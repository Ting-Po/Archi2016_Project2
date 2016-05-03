pipeline:  InstruM.o Memory.o Reg.o main.o Function.o IF.o IF_ID.o ID.o ID_EX.o EX.o EX_MEM.o MEM.o MEM_WB.o WB.o
	g++ -o pipeline InstruM.o Memory.o Reg.o main.o Function.o IF.o IF_ID.o ID.o ID_EX.o EX.o EX_MEM.o MEM.o MEM_WB.o WB.o
main.o: main.cpp Function.h InstruM.h Memory.h Reg.h Function.cpp InstruM.cpp Reg.cpp Memory.cpp
	g++ -g -c main.cpp
Function.o: Function.cpp Function.h InstruM.h Reg.h Memory.h
	g++ -g -c Function.cpp
InstruM.o: InstruM.cpp InstruM.h
	g++ -g -c InstruM.cpp
Memory.o: Memory.cpp Memory.h
	g++ -g -c Memory.cpp
Reg.o: Reg.h Reg.cpp
	g++ -g -c Reg.cpp
IF.o: IF.cpp IF.h InstruM.h Reg.h IF_ID.h
	g++ -g -c IF.cpp
IF_ID.o: IF_ID.cpp IF_ID.h
	g++ -g -c IF_ID.cpp
ID.o: ID.cpp ID.h IF_ID.h ID_EX.h Reg.h IF.h
	g++ -g -c ID.cpp
ID_EX.o: ID_EX.cpp ID_EX.h
	g++ -g -c ID_EX.cpp
EX.o: EX.cpp EX.h ID_EX.h EX_MEM.h IF_ID.h IF.h ID.h
	g++ -g -c EX.cpp
EX_MEM.o: EX_MEM.cpp EX_MEM.h
	g++ -g -c EX_MEM.cpp
MEM.o: MEM.cpp MEM.h Memory.h EX_MEM.h MEM_WB.h EX.h IF_ID.h ID_EX.h
	g++ -g -c MEM.cpp
MEM_WB.o: MEM_WB.cpp MEM_WB.h
	g++ -g -c MEM_WB.cpp
WB.o: WB.cpp WB.h Reg.h MEM_WB.h
	g++ -g -c WB.cpp
clean:
	rm -f *.o 
