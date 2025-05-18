#include <iostream>
#include <vector>
#include <chrono>
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

    auto start = std::chrono::high_resolution_clock::now();
    bfs.bfs(initialState);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;   

    cout << "Tempo de execução: " << diff.count() << " segundos" << endl;

    cout << "=--=--=--=--=--=--=--=--=--=--=--=--=" << endl;

    start = std::chrono::high_resolution_clock::now();
    dfs.dfs(initialState);
    end = std::chrono::high_resolution_clock::now();

    diff = end - start;   

    cout << "Tempo de execução: " << diff.count() << " segundos" << endl;

}