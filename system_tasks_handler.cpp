#include "system_tasks_handler.h"

using namespace Car::System;

SystemTaskHandler::SystemTaskHandler(Car::Network::CommandReceiver &cr,
                                     Car::Motion::MovementController& ctrl,
                                     QObject* parent) noexcept:
    QObject(parent),
    controller{ctrl},
    commandReceiver{cr}
{
    connect(&commandReceiver, &Car::Network::CommandReceiver::newMovementCommand,
            &controller, &Car::Motion::MovementController::Move);

    connect(&commandReceiver, &Car::Network::CommandReceiver::newEngineCommand,
            &controller, &Car::Motion::MovementController::ChangeEngineStatus);

}
