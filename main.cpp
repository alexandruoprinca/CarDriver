
#include <QCoreApplication>
#include <wiringPi.h>
#include <softPwm.h>
#include "server_adapter.h"
#include "command_receiver.h"
#include "system_tasks_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    constexpr auto movementPin1 = 27;
    constexpr auto directionPin1 = 23;
    constexpr auto motorEnableDc1 = 25;
    constexpr auto movementPin2 = 17;
    constexpr auto directionPin2 = 5;
    constexpr auto motorEnableDc2 = 13;

    if(wiringPiSetupGpio() == -1){
        return 1;
    }

    Car::Motion::MotorPair leftSide{motorEnableDc1, movementPin1, directionPin1};
    Car::Motion::MotorPair rightSide{motorEnableDc2, movementPin2, directionPin2};

    Car::Motion::Engine carEngine{};
    Car::Motion::MovementController contorller{leftSide, rightSide, carEngine};

    Car::Network::ServerAdapter server{};
    Car::Network::CommandReceiver commandReceiver{server};

    Car::System::SystemTaskHandler tasks{commandReceiver, contorller};

    return a.exec();
}
