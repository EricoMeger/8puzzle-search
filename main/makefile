CXXFLAGS = -std=c++17 -Iinclude
SRC = ./src/board.cpp ./src/bfs.cpp ./src/dfs.cpp main.cpp

all: compile

compile:
	g++ $(CXXFLAGS) $(SRC) -o puzzle

clean:
	rm -f puzzle