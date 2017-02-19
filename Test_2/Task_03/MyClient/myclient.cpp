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

void MyClient::onConnected()
{
    //composing packet
    QString str_packet;
    str_packet.fill('A', 105);
    loop_begin = QDateTime::currentMSecsSinceEpoch();
    str_packet.insert(0, QString::number(loop_begin));
    str_packet.insert(13, "[tcp_pckt]");

    QByteArray packet = str_packet.toUtf8().right(128);

    qDebug() << packet;

    m_p_tcpSocket->write(packet);
}

void MyClient::onReadyRead()
{
    QByteArray packet(m_p_tcpSocket->read(128));

//    latency = QDateTime::currentMSecsSinceEpoch() - loop_begin;
//    qDebug() << "latency : " << latency;

    qDebug() << packet;

//    //qDebug() << str_packet;

    m_p_tcpSocket->close();

//    Connect();
}
