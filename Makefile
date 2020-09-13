program:person.o stack.o main.o
	g++ ./lib/person.o ./lib/stack.o ./lib/main.o -o ./bin/a.exe
person.o:
	g++ -c ./src/person.cpp -o ./lib/person.o
stack.o:
	g++ -c ./src/stack.cpp -o ./lib/stack.o
main.o:
	g++ -c ./src/main.cpp -o ./lib/main.o
