#pragma once

#include "motor.h"
#include "movement_direction.h"

class MovementController{

public:
    MovementController(const Motor& frontLeft, const Motor& frontRight, const Motor& backLeft, const Motor& backRight);
    void Move(const MovementDirection directionToMove);

private:
    Motor& frontLeft;
    Motor& frontRight;
    Motor& backLeft;
    Motor& backRight;
};
