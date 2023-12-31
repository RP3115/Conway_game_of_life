main: main.o components.o
	g++ -o main main.o components.o
components.o: components.cpp components.h
	g++ -c -o components.o components.cpp 
main.o: main.cpp
	g++ -c -o main.o main.cpp 
clean:
	rm components.o main.o