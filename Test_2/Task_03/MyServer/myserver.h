#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QDataStream>
#include <QTime>
#include <QThread>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject* p_parent = 0);
    ~MyServer();
public slots:
    void start();
    void onNewConnection();
    //void onReadClient();
private:
    QTcpServer* m_p_tcpServer;
    QString m_packet;
};

#endif // MYSERVER_H
