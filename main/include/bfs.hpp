#ifndef BFS_HPP
#define BFS_HPP

#include "board.hpp"
#include <queue>
#include <set>

using std::queue, std::set;

class BFS {
    private:
        queue<Board> statesQueue;
        set<Board> visitedStates;
    public:
        BFS();
        ~BFS();
        void bfs(Board initialState);
};

#endif