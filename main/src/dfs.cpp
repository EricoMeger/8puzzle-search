#include "dfs.hpp"
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

DFS::DFS(){}

DFS::~DFS(){}

void DFS::dfs(Board initialState) {
    statesStack.push(initialState);
    visitedStates.insert(initialState);

    while(!statesStack.empty()) {
        Board currentState = statesStack.top();
        statesStack.pop();

        if(currentState.matchGoal()) {
            cout << "dfs solution found!!" << endl;
            cout << "movimentos: " << visitedStates.size() << endl;
            return;
        } 

        vector<Board> transitionStates = currentState.getPossibleStates();
        for(Board& child : transitionStates){ //For each
            if(!visitedStates.count(child)) {
                statesStack.push(child);
                visitedStates.insert(child);
            }
        }
    }

}
