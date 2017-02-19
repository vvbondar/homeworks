#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QTextCodec>

#include <vector>

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject* p_parent = 0);
    void Connect(const QString& host = "127.0.0.1", size_t port = 9999);
    ~MyClient();
private:
    QTcpSocket* m_p_tcpSocket;
public slots:
    void onConnected();
    void onReadyRead();
    void onThreadStarted();
private:
    QTime session_started;
    QTime session_ended;

    ulong loops = 300000;
    ulong packets_passed = 0;
    ulong throughput = 0;
    ulong latency = 0;
    ulong loop_begin = 0;
    ulong loop_end = 0;

    std::vector<ulong> latencies;
};

#endif // MYCLIENT_H
