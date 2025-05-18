#include <iostream>
#include <vector>
#include "board.hpp"
#include "bfs.hpp"

using std::vector, std::cout, std::endl;

int main() {
    BFS bfs;
    vector<vector<int>> board = {{4, 1, 2}, {3, 0, 5}, {6, 7, 8}};
    Board initialState(board);
    
    if(!initialState.isSolvable()) {
        cout << "The initial state is NOT solvable!" << endl;
        return 0;
    }

    bfs.search(initialState);

}