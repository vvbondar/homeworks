#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QDateTime>
#include <QDataStream>
#include <QThread>
#include <QTextCodec>

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject* p_parent = 0);
    void Connect(const QString& host = "127.0.0.1", size_t port = 9999);
    size_t getLatency(){}
    ~MyClient();
private:
    QTcpSocket* m_p_tcpSocket;
private slots:
    void onConnected();
    void onReadyRead();
private:
    ulong throughput = 0;
    ulong latency = 0;
    ulong loop_begin = 0;
    ulong loop_end = 0;
};

#endif // MYCLIENT_H
