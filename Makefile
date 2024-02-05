main: main.o Simulation.o Grid.o Cell.o Workflow.o
	g++ -o gameoflife main.o Simulation.o Grid.o Cell.o Workflow.o
Cell.o: Cell.cpp Cell.h
	g++ -c -o Cell.o Cell.cpp 
Grid.o: Grid.cpp Grid.h
	g++ -c -o Grid.o Grid.cpp 
Simulation.o: Simulation.cpp Simulation.h
	g++ -c -o Simulation.o Simulation.cpp 
Workflow.o: Workflow.cpp Workflow.h
	g++ -c -o Workflow.o Workflow.cpp 
main.o: main.cpp
	g++ -c -o main.o main.cpp 
clean:
#Windows
#	-del -fR gameoflife.exe *.o 
#Linux
	rm gameoflife *.o