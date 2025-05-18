#include "bfs.hpp"
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

BFS::BFS(){}

BFS::~BFS(){}

void BFS::bfs(Board initialState) {
    statesQueue.push(initialState);
    visitedStates.insert(initialState);

    while (!statesQueue.empty()) {
        Board currentState = statesQueue.front();
        statesQueue.pop(); //Pega o primeiro elemento e tira ele da fila

        if(currentState.matchGoal()) {
            cout << "bfs solution found!!!!!" << endl;
            return;
        }

        vector<Board> transitionStates = currentState.getPossibleStates();
        for(Board& child : transitionStates){ //For each
            if(!visitedStates.count(child)) {
                statesQueue.push(child);
                visitedStates.insert(child);

                //Assim que se descobre a possibilidade de um novo estado de transição, ja se marca ele como visitado pra evitar repetições
            }
        }
    }
}
