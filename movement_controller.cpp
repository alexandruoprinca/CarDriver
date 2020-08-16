#include "movement_controller.h"
#include <QtDebug>

MovementController::MovementController(DriveTrain& frontWheels, DriveTrain& backWheels, Engine& engine, QObject* parent) noexcept :
      QObject(parent),
      frontWheels{frontWheels},
      backWheels{backWheels},
      engine{engine}
{
}

void MovementController::Move(const MovementDirection directionToMove){

    if(engine.isTurnedOn()){
        qDebug() << "MocvementController::Moving into direction " << static_cast<char>(directionToMove) << '\n';
    }
}

void MovementController::ChangeEngineStatus(const EngineStatus status){

    qDebug() << "MovementController::ChangeEngineStatus into" << static_cast<char>(status) << '\n';

    if(status == EngineStatus::ON){
        engine.turnOn();
    } else {
        engine.turnOff();
    }
}
