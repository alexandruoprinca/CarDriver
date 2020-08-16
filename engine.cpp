#include "engine.h"

using namespace Car::Motion;

Engine::Engine(QObject* parent) noexcept:
    QObject(parent)
{
}

bool Engine::isTurnedOn() const noexcept{
    return status == EngineStatus::ON;
}

void Engine::turnOn() noexcept{
    if(status != EngineStatus::ON){
        status = EngineStatus::ON;
    }
}

void Engine::turnOff() noexcept{
    if(status != EngineStatus::OFF){
        status = EngineStatus::OFF;
    }
}
