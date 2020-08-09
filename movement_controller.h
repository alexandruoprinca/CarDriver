#pragma once

#include "motor_controller.h"

class MovementController{

public:
    MovementController(const MotorController& frontLeft, const MotorController& frontRight, const MotorController& backLeft, const MotorController& backRight);


private:
    MotorController frontLeft;
    MotorController frontRight;
    MotorController backLeft;
    MotorController backRight;
};
