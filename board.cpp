#include "board.hpp"
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

Board::Board(vector<vector<int>> board) {
  this->board = board;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == 0){
        blankPos[0] = i;
        blankPos[1] = j;
      }
    }
  }
}

Board::~Board(){}

//Para checar se um tabuleiro tem solução, é preciso checar se o ńumero de inversões é par
//Uma inversão ocorre quando, na sequência de números do tabuleiro, um número maior aparece antes de um número menro.
bool Board::isSolvable(const vector<vector<int>>& tabuleiro) {
  vector<int> lista;
  int totalInversions = 0;

  for(auto row : board) {
    for (int num : row) {
      if(num != 0){
        lista.push_back(num);
      }
    }
  }

  for(int i = 0; i < lista.size(); i++){
    //começa em j+1 para nao repetir elementos / comparar ja comparados
    for(int j = i+1; j < lista.size(); j++){
      if(lista[i] > lista[j]) {
        totalInversions++;
      }
    }
  }

  return totalInversions % 2 == 0;
}

// Overload do operador < é necessário para que objetos Board possam ser armazenados no set,
// o set precisa saber comparar e ordenar seus elementos internamente, então temos que "dizer" para ele como fazer isso com elementos da classe Board.
bool Board::operator<(const Board& board) const { //Não modifica o objeto atual (const { return... }) e nem o objeto recebido (const Board& ..)
  return this->board < board.board;
}

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
      int oldValue = matrix[new_posX][new_posY];
      matrix[new_posX][new_posY] = 0;
      matrix[blankPos[0]][blankPos[1]] = oldValue;
}

vector<Board> Board::getPossibleStates() {
  vector<Board> states;

  int transicoes[4] = {-1, 1, -1, 1};
  int new_posX, new_posY;

  for(int i = 0; i < 4; i++){
    new_posX = blankPos[0];
    new_posY = blankPos[1];

    if(i < 2) {
      new_posX = blankPos[0] + transicoes[i];
    } else {
      new_posY = blankPos[1] + transicoes[i];
    }

    if(new_posX >= 0 && new_posX < 3 && new_posY >= 0 && new_posY < 3) {
      vector<vector<int>> newState = board;
      swapWithBlank(newState, new_posX, new_posY);
      states.emplace_back(Board(newState));
    }
  }
  return states;    
}

