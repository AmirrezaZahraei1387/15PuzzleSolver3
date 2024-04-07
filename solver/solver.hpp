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
 *
 * all solvers must have the following signature:
 * void name(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);
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

/*
 * uses a BFS approach but works faster because it chooses the node with least number
 *  of literal moves to reach the goal state
 */
void solveWithMinLitMoves(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);

/*
 * uses a BFS approach but works faster.
 * We use a heuristic to actuate the score of each which is described as follows.
 *
 * totdist = total manhattan distance of current from base
 * seq = a tile in the centre scores 1;
 * a tile on a non-central square scores 0 if the tile is, in the clockwise direction,
 * followed by its proper successor.
 * such a tile scores 2 if it is not followed by its proper successor.
 *
 * H = totdist + 3 * seq
 */
void solveWithHScore(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);
#endif //INC_15PUZZLESOLVER3_SOLVER_HPP
