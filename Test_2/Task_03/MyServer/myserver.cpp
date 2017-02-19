#include "myserver.h"

MyServer::MyServer(QObject* p_parent)
    :QObject(p_parent)
    ,m_p_tcpServer(new QTcpServer(this))
{}

void MyServer::start()
{
    connect(m_p_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    if(!m_p_tcpServer->listen(QHostAddress::Any, 9999))
    {
        qDebug() << QTime::currentTime() << "Server is not started!";
        return;
    }

    qDebug() << QTime::currentTime() << "Server started.";
}

MyServer::~MyServer()
{
    delete m_p_tcpServer;
}

void MyServer::onNewConnection()
{
    QTcpSocket* p_client_socket = m_p_tcpServer->nextPendingConnection();
    qDebug() << QTime::currentTime() << "Client connected.";

    connect(p_client_socket, SIGNAL(readyRead()),    this,            SLOT(onReadClient()));
}

void MyServer::onReadClient()
{
    QTcpSocket* p_client_socket = static_cast<QTcpSocket*>(sender());
    QByteArray packet = p_client_socket->readAll();
    packet.replace(14, 3, "srv");
    p_client_socket->write(packet);
}
