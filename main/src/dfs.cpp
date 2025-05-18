#include "dfs.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector, std::map; 
using std::cout, std::endl;

DFS::DFS(){}

DFS::~DFS(){}

//Detalhe: nos testes a DFS leva em torno de ~4, 5 segundos pra resolver {{2, 3, 0}, {1, 4, 5}, {6, 7, 8}};
//Com a adição do map pra salvar o caminho leva em torno de ~7, 8.

void DFS::dfs(Board initialState) {
    statesStack.push(initialState);
    visitedStates.insert(initialState);
    map<Board, Board> parentMap;
    parentMap[initialState] = initialState;

    while(!statesStack.empty()) {
        Board currentState = statesStack.top();
        statesStack.pop();

        if(currentState.matchGoal()) {
            vector<Board> path;
            
            //começa no estado final (estado atual) e vai "voltando" pro estado anterior
            //usando o parentMap até chegar no estdao inicial, montando o caminho percorrido da solução até o começo 
            for(Board state = currentState; state != initialState; state = parentMap[state]) {
                path.push_back(state);
            }

            path.push_back(initialState);
            //inverte o caminho pra mostrar na ordem começo - fim
            std::reverse(path.begin(), path.end());

            cout << "dfs solution found!!" << endl;
            cout << "Tamanho do caminho para a solução: " << path.size() << endl;
            cout << "Estados visitados: " << visitedStates.size() << endl;
            cout << "Caminho tomado: " << endl;
            //muito movimento pra mostrar
            // for(auto& instance : path){
            //     instance.printBoard();
            //     cout << endl;
            // }

            return;
        } 

        vector<Board> transitionStates = currentState.getPossibleStates();
        for(Board& child : transitionStates){ //For each
            if(!visitedStates.count(child)) {
                statesStack.push(child);
                visitedStates.insert(child);
                parentMap[child] = currentState;
            }
        }
    }

}
