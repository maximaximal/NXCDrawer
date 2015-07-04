#include "NXTCommunicator.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>

#include <QDebug>

NXTCommunicator::NXTCommunicator()
{
    m_serialPort = new QSerialPort();
}
NXTCommunicator::~NXTCommunicator()
{
    delete m_serialPort;
}

void NXTCommunicator::connect()
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();

    qDebug() << "Number of available ports: " << serialPorts.count();

    for(auto &info : serialPorts)
    {
        qDebug() << "Serial Port Name: " << info.portName();
        qDebug() << "Serial Port Desc: " << info.description();
    }
}

