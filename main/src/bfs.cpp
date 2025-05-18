#include "bfs.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector, std::map; 
using std::cout, std::endl;

BFS::BFS(){}

BFS::~BFS(){}

void BFS::bfs(Board initialState) {
    statesQueue.push(initialState);
    visitedStates.insert(initialState);
    map<Board, Board> parentMap;
    parentMap[initialState] = initialState;

    while (!statesQueue.empty()) {
        Board currentState = statesQueue.front();
        statesQueue.pop(); //Pega o primeiro elemento e tira ele da fila

        if(currentState.matchGoal()) {
            vector<Board> path;
            
            for(Board state = currentState; state != initialState; state = parentMap[state]){
                path.push_back(state);
            }

            path.push_back(initialState);
            std::reverse(path.begin(), path.end());
            
            cout << "bfs solution found!!!!!" << endl;
            cout << "Tamanho do caminho para a solução: " << path.size() << endl;
            cout << "estados visitados: " << visitedStates.size() << endl;
            cout << "Caminho tomado: " << endl;
            for(auto& instance : path) {
                instance.printBoard();
                cout << endl;
            }
            
            return;
        }

        vector<Board> transitionStates = currentState.getPossibleStates();
        for(Board& child : transitionStates){ //For each
            if(!visitedStates.count(child)) {
                statesQueue.push(child);
                visitedStates.insert(child);
                parentMap[child] = currentState;

                //Assim que se descobre a possibilidade de um novo estado de transição, ja se marca ele como visitado pra evitar repetições
            }
        }
    }
}
