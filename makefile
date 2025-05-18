all: compile

compile:
	g++ -std=c++17 board.cpp main.cpp -o main
	./main