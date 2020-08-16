#include <QCoreApplication>
#include <wiringPi.h>
#include "server_adapter.h"
#include "command_receiver.h"
#include "system_tasks_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    wiringPiSetup();


    constexpr auto firstWheelPin{1};
    constexpr auto secondWheelPin{2};
    constexpr auto thirdWheelPin{3};
    constexpr auto fourthWheelPin{4};
    Car::Motion::DriveTrain frontWheels{Car::Motion::Motor{firstWheelPin}, Car::Motion::Motor{secondWheelPin}};
    Car::Motion::DriveTrain backWheels{Car::Motion::Motor{thirdWheelPin}, Car::Motion::Motor{fourthWheelPin}};
    Car::Motion::Engine carEngine{};
    Car::Motion::MovementController contorller{frontWheels, backWheels, carEngine};

    Car::Network::ServerAdapter server{};
    Car::Network::CommandReceiver commandReceiver{server};

    Car::System::SystemTaskHandler tasks{commandReceiver, contorller};

    return a.exec();
}
