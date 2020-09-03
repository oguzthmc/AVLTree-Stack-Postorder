CXXFLAGS= -I "./include"

entire: all run

all: compile test

test: compile
	g++ ./lib/AVLTree.o ./lib/Stack.o ./lib/Main.o ./lib/Person.o ./lib/ProgramController.o -o ./bin/test
	
compile:
	g++ $(CXXFLAGS) -c ./src/AVLTree.cpp -o ./lib/AVLTree.o
	g++ $(CXXFLAGS) -c ./src/Main.cpp -o ./lib/Main.o 
	g++ $(CXXFLAGS) -c ./src/Stack.cpp -o ./lib/Stack.o
	g++ $(CXXFLAGS) -c ./src/Person.cpp -o ./lib/Person.o
	g++ $(CXXFLAGS) -c ./src/ProgramController.cpp -o ./lib/ProgramController.o
		
run:
	./bin/test.exe
	
