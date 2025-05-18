#include <iostream>
#include <vector>
#include "board.hpp"
#include "bfs.hpp"

using std::vector, std::cout, std::endl;

int main() {
    BFS bfs;
    vector<vector<int>> board = {{2, 1, 5}, {3, 4, 0}, {7, 6, 8}};
    Board initialState(board);
    
    if(!initialState.isSolvable()) {
        cout << "The initial state is NOT solvable!" << endl;
        return 0;
    }

    bfs.search(initialState);

}