#include "system_tasks_handler.h"

SystemTaskHandler::SystemTaskHandler(CommandReceiver &cr, MovementController& ctrl, QObject* parent) noexcept:
    QObject(parent),
    controller{ctrl},
    commandReceiver{cr}
{
    connect(&commandReceiver, &CommandReceiver::newMovementCommand,
            &controller, &MovementController::Move);

    connect(&commandReceiver, &CommandReceiver::newEngineCommand,
            &controller, &MovementController::ChangeEngineStatus);

}
