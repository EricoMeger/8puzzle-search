all: compile

compile:
	g++ -std=c++17 board.cpp bfs.cpp main.cpp -o main
	./main