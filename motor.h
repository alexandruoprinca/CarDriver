#pragma once

#include "pin_state.h"
#include "rotation_direction.h"

class Motor{
public:
    Motor(const int pinNumber);
    void Rotate(const RotationDirection direction);

private:
    void setState(const PinState state);
private:
    int pinNumber;
};
