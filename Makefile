program:stack.o main.o
	g++ ./lib/stack.o ./lib/main.o -o ./bin/program.exe
stack.o:
	g++ -c ./src/stack.cpp -o ./lib/stack.o
main.o:
	g++ -c ./src/main.cpp -o ./lib/main.o
