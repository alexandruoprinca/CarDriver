#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <optional>
#include <QChar>
#include <QTcpServer>

class ConnectionHandler: public QObject{
    Q_OBJECT

public:
    explicit ConnectionHandler(QObject *parent = 0);
    bool listen();
    void disconect();
    bool canRead() const;
    bool canWrite() const;
    QChar readChar();
    bool writeChar(const QChar message);

signals:

public slots:
    void connected();
    void disconnected();

private:
    void connect();


private:
    QTcpServer server;
    QTcpSocket* connexion;
};

