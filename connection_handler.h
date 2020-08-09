#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <optional>

class ConnectionHandler: public QObject{

    Q_OBJECT

public:
    explicit ConnectionHandler(QObject *parent = 0);
    void disconect();
    bool canRead() const;
    bool canWrite() const;
    std::optional<QByteArray> readChar();
    bool writeChar(const QByteArray& message);

signals:

public slots:
    void connected();
    void disconnected();

private:
    void connect();


private:
    QTcpSocket* connexion;
};

