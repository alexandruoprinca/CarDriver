#pragma once
#include "motor.h"

class DriveTrain{
public:
    constexpr DriveTrain(const Motor& leftMotor, const Motor& rightMotor) noexcept :
        leftSide{leftMotor},
        rightSide{rightMotor}
    {
    }
private:
    Motor leftSide;
    Motor rightSide;
};
