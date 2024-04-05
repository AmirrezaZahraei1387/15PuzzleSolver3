#include <iostream>
#include "nodePuz/nodePuz.hpp"
#include "solver/solver.hpp"

int main() {

    constexpr std::int32_t DEFAULT_BASE_CONFIG{123804765};

    std::int32_t init_config;
    std::int32_t base_config;
    int algol{0};

    std::cout<<"enter the init config:";
    std::cin>>init_config;

    std::cout<<"enter the base config(0 to use default):";
    std::cin>>base_config;

    if(base_config == 0)
        base_config = DEFAULT_BASE_CONFIG;

    std::cout<<"1 - DFS\n"
               "2 - BFS\n"
               "3 - number of tiles out of place.\n"
               "4 - minimum number of moves to reach the goal state.\n"
               "5 - the heuristic H."<<std::endl;
    std::cout<<"enter an algorithm (enter the number of the intended algol):";
    std::cin>>algol;

    // building the nodes
    NodePuz init(init_config, {}, 0);
    NodePuz endto(base_config, {}, 0);

    // building the move tracker
    MoveTracker mvt;

    std::cout<<std::endl;
    std::cout<<"init is:"<<std::endl;
    std::cout<<init<<std::endl;
    std::cout<<"goal is:"<<std::endl;
    std::cout<<endto<<std::endl;

    switch (algol) {
        case 1:
            std::cout<<"warning!!: the chosen algorithm can take unreasonable amount of time!"<<std::endl;
            solveWithDFS(init, endto, mvt);
            break;
        case 2:
            std::cout<<"warning!!: the chosen algorithm can take unreasonable amount of time!"<<std::endl;
            solveWithBFS(init, endto, mvt);
            break;
        case 3:
            solveWithTilesOut(init, endto, mvt);
            break;
        case 4:
            solveWithMinLitMoves(init, endto, mvt);
            break;
        case 5:
            solveWithHScore(init, endto, mvt);
            break;
        default:
            std::cerr<<"error: wrong selection."<<std::endl;
            std::exit(1);
    }



    std::cout<<"moves proceeded to reach the goal state are:\n"<<std::endl;
    for(const auto& mov: mvt)
        std::cout<<mov<<std::endl;

    std::cout<<std::endl;

    std::cout<<"number of moves is:"<<mvt.size()<<std::endl;

    // the moves are produced a small function will test if those moves get ys to goal state
    // from init state. True if yes, false otherwise
    std::cout<<"(testing if moves really result in goal config):"<<std::boolalpha
    <<(applyMoveTracker(init, mvt) == endto)<<std::endl;

    return 0;
}
