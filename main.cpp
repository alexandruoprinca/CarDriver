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
    DriveTrain frontWheels{Motor{firstWheelPin}, Motor{secondWheelPin}};
    DriveTrain backWheels{Motor{thirdWheelPin}, Motor{fourthWheelPin}};
    Engine carEngine{};
    MovementController contorller{frontWheels, backWheels, carEngine};

    ServerAdapter server{};
    CommandReceiver commandReceiver{server};

    SystemTaskHandler tasks{commandReceiver, contorller};





    return a.exec();
}
