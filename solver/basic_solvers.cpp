//
// Created by mzahr on 4/2/2024.
//
#include <stack>
#include <queue>
#include <iostream>
#include "solver.hpp"

/*
 * it might be seen that the BFS version works very faster than the DFS.
 * this is because of the nature of them and the way these algorithms try to
 * find a solution.
 *
 * the DFS dig deep into the graph this can wast a lot of time if the solution is
 * not there as is the case for small puzzle.
 *
 * The BFS however check the adjacent nodes and for a small puzzle is likelier to
 * find the answer quicker there.
 */

static void solveWithDFS(const NodePuz &current,
                         const NodePuz &endto,
                         std::unordered_set<std::int32_t>& visited,
                         MoveTracker& mvt) {

    std::stack<NodePuz> stack;
    stack.push(current);
    visited.insert(current.getConfig());

    while (!stack.empty()) {
        const auto np = stack.top();
        stack.pop();

        if (np == endto) {
            mvt = np.getMoves();
            return;
        }

        for (const auto& mov : ALL_MOVES) {
            auto temp(np);

            if (!temp.move(mov)) continue;

            if (visited.count(temp.getConfig()) == 0) {
                visited.insert(temp.getConfig());
                stack.push(std::move(temp));
            }
        }
    }
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
