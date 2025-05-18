#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

using std::vector;

class Board {
    private:
        vector<vector<int>> board;
        int blank_pos[2];
    public:
        Board(vector<vector<int>> board);
        ~Board();
        void printBoard();
        bool matchGoal();
        void swapWithBlank(vector<vector<int>>& matrix, int new_posX, int new_posY);
        vector<Board> getPossibleStates();
};

#endif