#include "motor.h"
#include <QDebug>
#include <chrono>

using namespace Car::Motion;

void Motor::Rotate(const RotationDirection direction){
    qDebug() << "Rotating in direction" << static_cast<char>(direction) << '\n';
}
