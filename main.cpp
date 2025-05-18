#include <iostream>
#include <vector>
#include "board.hpp"
#include "bfs.hpp"

using std::vector, std::cout, std::endl;

int main() {
    vector<vector<int>> board = {{3, 1, 2}, {0, 4, 5}, {6, 7, 8}};
    Board b(board);
    // b.printBoard();
    // // cout << b.matchGoal();

    // auto possibilities = b.getPossibleStates();
    // for(int i = 0; i < 4; i++){
    //     cout << "---------" << endl;
    //     possibilities[i].printBoard();
    // }
    BFS bfs;
    bfs.search(board);

}