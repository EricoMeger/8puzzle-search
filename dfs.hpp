#ifndef DFS_HPP
#define DFs_HPP

#include "board.hpp"
#include <stack>
#include <set>

using std::stack, std::set;

class DFS {
    private:
        stack<Board> statesStack;
        set<Board> visitedStates;
        bool foundGoal = false;
    public:
        DFS();
        ~DFS();
        void dfs(Board currentState);
};

#endif