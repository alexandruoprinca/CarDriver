#pragma once

#include <variant>
#include <QTcpSocket>
#include "movement_direction.h"
#include "engine_status.h"
#include "server_adapter.h"

namespace Car::Network{

    class CommandReceiver : public QObject{

        Q_OBJECT

    public:
        explicit CommandReceiver(ServerAdapter& connecter, QObject* parent=0);

    signals:
        void newMovementCommand(Car::Motion::MovementDirection);
        void newEngineCommand(Car::Motion::EngineStatus);

    public slots:
        void getCommand(const QByteArray data);

    private:
        ServerAdapter& connexion;
    };

}
