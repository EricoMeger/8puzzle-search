#include <iostream>
#include <vector>
#include "board.hpp"

using std::vector, std::cout, std::endl;

int main() {
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    Board b(board);
    b.printBoard();
    // cout << b.matchGoal();

    auto possibilities = b.getPossibleStates();
    for(int i = 0; i < 4; i++){
        cout << "---------" << endl;
        possibilities[i].printBoard();
    }
}