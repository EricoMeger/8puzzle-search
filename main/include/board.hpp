#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

using std::vector;

class Board {
    private:
        vector<vector<int>> board;
        int blankPos[2];
    public:
        Board();
        Board(vector<vector<int>> board);
        ~Board();
        bool isSolvable();
        bool operator<(const Board& other) const;
        bool operator!=(const Board& other) const;
        void printBoard();
        bool matchGoal();
        void swapWithBlank(vector<vector<int>>& matrix, int new_posX, int new_posY);
        vector<Board> getPossibleStates();
};

#endif