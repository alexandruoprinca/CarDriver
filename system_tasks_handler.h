#pragma once

#include "command_receiver.h"
#include "movement_controller.h"
#include "wiringPi.h"
#include "engine_status.h"

namespace Car::System{

    class SystemTaskHandler : public QObject{

    Q_OBJECT

    public:
        explicit SystemTaskHandler(Car::Network::CommandReceiver& cr, Car::Motion::MovementController& ctrl, QObject* parent=0) noexcept;
    private:
        Car::Motion::MovementController& controller;
        Car::Network::CommandReceiver& commandReceiver;

    };

}
