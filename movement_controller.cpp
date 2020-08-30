#include "movement_controller.h"
#include <QtDebug>

using namespace Car::Motion;

MovementController::MovementController(MotorPair& frontWheels, MotorPair& backWheels, Engine& engine, QObject* parent) noexcept :
      QObject(parent),
      leftWheels{frontWheels},
      rightWheels{backWheels},
      engine{engine}
{
}

void MovementController::Move(const MovementDirection directionToMove){

    if(engine.isTurnedOn()){
        qDebug() << "MocvementController::Moving into direction " << static_cast<char>(directionToMove) << '\n';
        switch(directionToMove){
        case MovementDirection::FORWARD:
            leftWheels.Rotate(RotationDirection::FORWARD);
            break;
        case MovementDirection::BACKWARD:
            leftWheels.Rotate(RotationDirection::BACKWARD);
            break;
        case MovementDirection::LEFT:
            rightWheels.Rotate(RotationDirection::FORWARD);
            break;
        case MovementDirection::RIGHT:
            leftWheels.Rotate(RotationDirection::FORWARD);
            break;
        }
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
