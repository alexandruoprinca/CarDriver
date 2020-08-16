#pragma once

#include "command_receiver.h"
#include "movement_controller.h"
#include "motor.h"
#include "wiringPi.h"
#include "engine_status.h"

class SystemTaskHandler : public QObject{

Q_OBJECT

public:
    explicit SystemTaskHandler(CommandReceiver& cr, MovementController& ctrl, QObject* parent=0) noexcept;
private:
    MovementController& controller;
    CommandReceiver& commandReceiver;

};
