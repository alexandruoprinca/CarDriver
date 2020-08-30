#pragma once

#include <QObject>
#include "movement_direction.h"
#include "drive_train.h"
#include "engine.h"

namespace Car::Motion{

    class MovementController: public QObject{

    public:
        MovementController(MotorPair& leftWheels, MotorPair& rightWheels, Engine& engine, QObject* parent=0) noexcept;
    public slots:
        void Move(const MovementDirection directionToMove);
        void ChangeEngineStatus(const EngineStatus status);

    private:
        MotorPair& leftWheels;
        MotorPair& rightWheels;
        Engine& engine;
    };

}
