//
// Created by mzahr on 4/2/2024.
//
#ifndef INC_15PUZZLESOLVER3_SOLVER_HPP
#define INC_15PUZZLESOLVER3_SOLVER_HPP
#include <unordered_set>
#include "../nodePuz/nodePuz.hpp"
#include "../nodePuz/tracker.hpp"

/*
 * the init variable represents the starting config and the
 * endto represents the goal config.
 * the mvt is MoveTracker object that
 * contains the moves needed to proceed to reach the endto state.
 */

/*
 *solve the puzzle with a pure DFS solution and no optimization
 */
void solveWithDFS(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);


/*
 * solve the puzzle with a pure BFS approach and no optimization
 */
void solveWithBFS(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);

/*
 * uses a BFS approach but works faster because it chooses the next
 * node to search based upon the number of tiles out of place.
 *
 * it basically means the number of tiles that are not in their actual place
 * in the endto configuration.
 */
void solveWithTilesOut(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);
#endif //INC_15PUZZLESOLVER3_SOLVER_HPP
