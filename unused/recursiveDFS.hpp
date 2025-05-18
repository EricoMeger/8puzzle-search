// #ifndef DFS_HPP
// #define DFs_HPP

#include "board.hpp"
#include <set>

using std::set;

class DFS {
    private:
        set<Board> visitedStates;
        bool foundGoal = false;
    public:
        DFS();
        ~DFS();
        void main(Board initialState);
        void dfs(Board currentState);
};

// #endif