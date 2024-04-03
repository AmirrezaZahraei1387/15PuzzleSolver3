//
// Created by KAVOSH on 4/2/2024.
//
#ifndef INC_15PUZZLE3ENGINE_TRACKER_HPP
#define INC_15PUZZLE3ENGINE_TRACKER_HPP
#include <ostream>
#include <vector>
#include <array>

class MoveUnit{
public:
    enum MV{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE,
    };

    explicit MoveUnit(MV m);
    MoveUnit(const MoveUnit& other);
    MoveUnit& operator=(const MoveUnit& other);

    MoveUnit();

    friend std::ostream& operator<<(std::ostream& out, const MoveUnit& mu);

    [[nodiscard]] MV get() const;
    void set(MV new_mv);
private:
    MV mov;
};

// all the moves to facilitate iteration
inline const std::array<MoveUnit, 4> ALL_MOVES{
    MoveUnit(MoveUnit::LEFT),
    MoveUnit(MoveUnit::RIGHT),
    MoveUnit(MoveUnit::UP),
    MoveUnit(MoveUnit::DOWN),
};

// the move tracker tracks down the moves of the each node
// it is composited with NodePuz class
using MoveTracker = std::vector<MoveUnit>;

#endif //INC_15PUZZLE3ENGINE_TRACKER_HPP
