#pragma once

#include <QObject>
#include "motor.h"
#include "movement_direction.h"
#include "drive_train.h"
#include "engine.h"

namespace Car::Motion{

    class MovementController: public QObject{

    public:
        MovementController(DriveTrain& frontWheels, DriveTrain& backWheels, Engine& engine, QObject* parent=0) noexcept;
    public slots:
        void Move(const MovementDirection directionToMove);
        void ChangeEngineStatus(const EngineStatus status);

    private:
        DriveTrain& frontWheels;
        DriveTrain& backWheels;
        Engine& engine;
    };

}
