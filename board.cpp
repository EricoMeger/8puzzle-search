#include "board.hpp"
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

Board::Board(vector<vector<int>> board) {
  this->board = board;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == 0){
        blank_pos[0] = i;
        blank_pos[1] = j;
      }
    }
  }
}

Board::~Board(){}

void Board::printBoard() {
  for (auto row : board) {
    for (auto col : row) {
      cout << "|" << col << "|";
    }
    cout << endl;
  }
}

bool Board::matchGoal() {
  vector<vector<int>> goal = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

  return board == goal;
}

void Board::swapWithBlank(vector<vector<int>>& matrix, int new_posX, int new_posY) {
      int old_value = matrix[new_posX][new_posY];
      matrix[new_posX][new_posY] = 0;
      matrix[blank_pos[0]][blank_pos[1]] = old_value;
}

vector<Board> Board::getPossibleStates() {
  vector<Board> states;

  int transicoes[4] = {-1, 1, -1, 1};
  int new_posX, new_posY;

  for(int i = 0; i < 4; i++){
    new_posX = blank_pos[0];
    new_posY = blank_pos[1];

    if(i < 2) {
      new_posX = blank_pos[0] + transicoes[i];
    } else {
      new_posY = blank_pos[1] + transicoes[i];
    }

    if(new_posX >= 0 && new_posX < 3 && new_posY >= 0 && new_posY < 3) {
      vector<vector<int>> newState = board;
      swapWithBlank(newState, new_posX, new_posY);
      states.emplace_back(Board(newState));
    }
  }
  return states;    
}

