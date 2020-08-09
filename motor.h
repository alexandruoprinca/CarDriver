#pragma once

#include "pin_state.h"

class Motor{
public:
    Motor(const int pinNumber);
    void setState(const PinState state);
private:
    int pinNumber;
};
