#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>


class ServerAdapter : public QObject{

    Q_OBJECT

public:
    explicit ServerAdapter(QObject *parent=0);
    void writeChar(QByteArray character);

signals:
    void newMessage(QByteArray);

public slots:
    void connected();
    void readForData();
    void discardSocket();

private:
    QTcpServer server{};
    QTcpSocket* activeConnection;

};
