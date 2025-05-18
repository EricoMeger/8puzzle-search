#include <iostream>
#include <vector>
#include "board.hpp"
#include "bfs.hpp"
#include "dfs.hpp"

using std::vector, std::cout, std::endl;

int main() {
    BFS bfs;
    DFS dfs;
    vector<vector<int>> board = {{2, 3, 0}, {1, 4, 5}, {6, 7, 8}};
    Board initialState(board);
    
    if(!initialState.isSolvable()) {
        cout << "The initial state is NOT solvable!" << endl;
        return 0;
    }

    bfs.bfs(initialState);
    dfs.dfs(initialState);

}