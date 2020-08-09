#pragma once

#include <motor.h>
#include <direction.h>

class MotorController{
public:
    MotorController(Motor& motor):motor{motor}{}
    void Move(const Direction direction);

private:
    Motor motor;

};

