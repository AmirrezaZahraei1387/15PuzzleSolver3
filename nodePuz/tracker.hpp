//
// Created by KAVOSH on 4/2/2024.
//
#ifndef INC_15PUZZLE3ENGINE_TRACKER_HPP
#define INC_15PUZZLE3ENGINE_TRACKER_HPP
#include <ostream>
#include <vector>

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

using MoveTracker = std::vector<MoveUnit>;
#endif //INC_15PUZZLE3ENGINE_TRACKER_HPP
