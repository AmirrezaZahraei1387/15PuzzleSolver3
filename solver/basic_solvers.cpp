//
// Created by mzahr on 4/2/2024.
//
#include <stack>
#include <queue>
#include <iostream>
#include "solver.hpp"

static bool solveWithDFS(const NodePuz &current,
                         const NodePuz &endto,
                         std::unordered_set<std::int32_t>& visited,
                         MoveTracker& mvt) {
    if (current == endto) {
        mvt = current.getMoves();
        return true;
    }

    for (const auto &mov: ALL_MOVES) {
        auto temp(current);

        if (!temp.move(mov)) continue;

        if (visited.count(temp.getConfig()) == 0) {
            visited.insert(temp.getConfig());
            if(solveWithDFS(temp, endto, visited, mvt))
                return true;
        }
    }

    return false;
}

static void solveWithBFS(const NodePuz &current,
                         const NodePuz &endto,
                         std::unordered_set<std::int32_t>& visited,
                         MoveTracker& mvt) {

    std::queue<NodePuz> pq;
    pq.push(current);
    visited.insert(current.getConfig());

    while(!pq.empty()) {

        const auto np(pq.front());
        pq.pop();

        if (np == endto) {
            mvt = np.getMoves();
            return;
        }

        for(const auto& mov: ALL_MOVES){

            auto temp(np);

            if(!temp.move(mov)) continue;

            if(visited.count(temp.getConfig()) == 0){
                visited.insert(temp.getConfig());
                pq.push(std::move(temp));
            }
        }
    }
}

void solveWithDFS(const NodePuz &init, const NodePuz &endto, MoveTracker& mvt) {
    std::unordered_set<std::int32_t> visited;
    solveWithDFS(init, endto, visited, mvt);
}

void solveWithBFS(const NodePuz &init, const NodePuz &endto, MoveTracker &mvt) {
    std::unordered_set<std::int32_t> visited;
    solveWithBFS(init, endto, visited, mvt);
}
