./bin/debug/main_debug: main.o authentication.o
	g++ main.o -lauth -o ./bin/debug/main_debug -L lib -no-pie -static

main.o: main.cpp
	g++ -c main.cpp -o main.o -I include

authentication.o: ./lib/authentication.cpp
	g++ -c ./lib/authentication.cpp -o authentication.o
