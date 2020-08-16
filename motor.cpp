#include "motor.h"
#include <QDebug>
#include <chrono>

void Motor::Rotate(const RotationDirection direction){
    qDebug() << "Rotating in direction" << static_cast<char>(direction) << '\n';
}
