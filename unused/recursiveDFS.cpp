#include "recursiveDFS.hpp"
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

DFS::DFS(){}

DFS::~DFS(){}

//Stack overflow

void DFS::dfs(Board currentState) {
    if(foundGoal) return;

    if(currentState.matchGoal()) {
        cout << "dfs solution found!!" << endl;
        foundGoal = true;
        return;
    }

    vector<Board> transitionStates = currentState.getPossibleStates();
    for(Board& child : transitionStates){ //For each
            if(!visitedStates.count(child)) {
                visitedStates.insert(child);
                dfs(child);
            }
        }
}

void DFS::main(Board initialState) {
    visitedStates.insert(initialState);
    dfs(initialState);
}