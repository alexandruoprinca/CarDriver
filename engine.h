#pragma once

#include <QObject>
#include "engine_status.h"

class Engine : public QObject{
public:
    Engine(QObject* parent=0) noexcept;
    bool isTurnedOn() const noexcept;
    void turnOn() noexcept;
    void turnOff() noexcept;
private:
    EngineStatus status{EngineStatus::OFF};
};
