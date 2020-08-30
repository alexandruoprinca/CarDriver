#pragma once
#include "rotation_direction.h"
#include <wiringPi.h>
#include <softPwm.h>

namespace Car::Motion{

    class MotorPair{
    public:
        typedef int Pin;
        constexpr MotorPair(const Pin en, const Pin movement, const Pin direction) noexcept :
            enPin{en},
            movement{movement},
            direction{direction}
        {
            pinMode(movement, OUTPUT);
            pinMode(direction, OUTPUT);
            pinMode(enPin, PWM_OUTPUT);
            softPwmCreate(enPin, 0, 100);
            softPwmWrite(enPin, 99);
        }

        void Rotate(const RotationDirection rotationDirection){
            const auto directionImpulse = rotationDirection == RotationDirection::FORWARD ? LOW : HIGH;
            const auto movementImpulse = !directionImpulse;
            const auto stopImpulse = !movementImpulse;
            digitalWrite(movement, movementImpulse);
            digitalWrite(direction, directionImpulse);
            delay(500);
            digitalWrite(movement, stopImpulse);
        }


    private:
        Pin enPin;
        Pin movement;        Pin direction;

    };

}
