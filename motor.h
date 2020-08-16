#pragma once

#include "pin_state.h"
#include "rotation_direction.h"

class Motor{
public:
    constexpr Motor(const int pinNumber) noexcept:
        pinNumber{pinNumber}
    {
    }
    void Rotate(const RotationDirection direction);

//private:
//    void setState(const PinState state){}
private:
    int pinNumber;
};
