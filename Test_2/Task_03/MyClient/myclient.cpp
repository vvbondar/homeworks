#include "myclient.h"

MyClient::MyClient(QObject* p_parent)
    :QObject(p_parent)
    ,m_p_tcpSocket(new QTcpSocket(this))
{
    connect(m_p_tcpSocket, SIGNAL(connected()), SLOT(onConnected()));
    connect(m_p_tcpSocket, SIGNAL(readyRead()), SLOT(onReadyRead()));
}

MyClient::~MyClient()
{
    delete m_p_tcpSocket;
}

void MyClient::Connect(const QString &host, size_t port)
{
    m_p_tcpSocket->connectToHost(host, port);
}

void MyClient::onThreadStarted()
{
    Connect();
}

void MyClient::onConnected()
{
    session_started = QTime::currentTime();

    //composing packet
    QString str_packet;
    str_packet.fill('A', 105);
    loop_begin = QDateTime::currentMSecsSinceEpoch();
    str_packet.insert(0, QString::number(loop_begin));
    str_packet.insert(13, "[cli_pckt]");

    QByteArray packet = str_packet.toUtf8().right(128);

    qDebug() << QTime::currentTime() << " started";

    m_p_tcpSocket->write(packet);
}

void MyClient::onReadyRead()
{
    QByteArray packet(m_p_tcpSocket->readAll());
    QString str_packet = QString::fromUtf8(packet.data());



    if(loops-- && str_packet.contains("[srv_pckt]"))
    {
        packets_passed++;
        loop_end = QDateTime::currentMSecsSinceEpoch();

        latency = loop_end - str_packet.mid(0, 13).toULong();
        latencies.push_back(latency);

        if(loops%(15000) == 0)
        {
            qDebug() << "packet" << str_packet.mid(0, 13).toULong() << "came back";
        }

        str_packet.replace(0, 13, QString::number(loop_end));
        packet.replace(14, 3, "cli");
        QByteArray packet = str_packet.toUtf8().right(128);

        m_p_tcpSocket->write(packet);
    }
    else
    {
        qDebug() << QTime::currentTime() << "finished";
        qDebug() << "==============================";
        qDebug() << "session duration              : " << session_started.elapsed() << "ms";
        qDebug() << "packages passed               : " << packets_passed;
        qDebug() << "max latency during session    : "
                << *std::max_element(latencies.begin(), latencies.end());

        throughput = (latencies.size() * 1000) / session_started.elapsed();

        qDebug() << "throughput                    : " << throughput << "pps";
        qDebug() << "==============================";

        m_p_tcpSocket->disconnect();
    }
}
