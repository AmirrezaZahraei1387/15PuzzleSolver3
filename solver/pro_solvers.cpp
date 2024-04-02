//
// Created by mzahr on 4/2/2024.
//
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "../nodePuz/nodePuz.hpp"
#include "solver.hpp"


struct TilesOutOfPlace{

    static int calcScore(const NodePuz& current, const NodePuz& endto){


        int counter{0};

        for(int i{0}; i < NodePuz::MAX_ROWS; ++i) {
            for (int j{0}; j < NodePuz::MAX_COLUMNS; ++j) {
                if (current.at(i, j) != endto.at(i, j))
                    ++counter;
            }
        }
        return counter;
    }
};

// it packs the NodePuz with its optimization score out
template<typename CalcScore>
struct PrWENode{
public:
    NodePuz np;
    int out{0}; // out is a special score that affects the selection of nodes

    friend bool operator>(const PrWENode& p1,const PrWENode& p2){return p1.out > p2.out;}

    void calcOut(const NodePuz& x)// must calculate and set the out
    {
        out = CalcScore::calcScore(np, x) + np.getDepth();
    }

};

template<typename CalcScore>
static void solveWithOptimizedBFS(PrWENode<CalcScore> &current,
                         const NodePuz &endto,
                         std::unordered_set<std::int32_t>& visited,
                         MoveTracker& mvt) {

    using PqPrio = std::priority_queue<PrWENode<CalcScore>, std::vector<PrWENode<CalcScore>>, std::greater<>>;

    PqPrio pq;
    pq.push(current);
    visited.insert(current.np.getConfig());

    while(!pq.empty()) {

        const auto np(pq.top());

        pq.pop();

        if (np.np == endto) {
            mvt = np.np.getMoves();
            return;
        }

        for(const auto& mov: ALL_MOVES){

            auto temp(np);

            if(!temp.np.move(mov)) continue;

            if(visited.count(temp.np.getConfig()) == 0){

                // going one level deeper
                temp.np.inc_depth();

                // calculating the score and setting the out
                temp.calcOut(endto);

                visited.insert(temp.np.getConfig());
                pq.push(std::move(temp));
            }
        }
    }
}


void solveWithTilesOut(const NodePuz &init, const NodePuz &endto, MoveTracker& mvt) {
    std::unordered_set<std::int32_t> visited;
    PrWENode<TilesOutOfPlace> start{.np = init};

    solveWithOptimizedBFS<TilesOutOfPlace>(start, endto, visited, mvt);
}