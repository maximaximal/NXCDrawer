#ifndef NXTCOMMUNICATOR_H
#define NXTCOMMUNICATOR_H

#include <QSerialPort>

class NXTCommunicator
{
public:
    NXTCommunicator();
    virtual ~NXTCommunicator();

    void connect();
private:
    QSerialPort *m_serialPort;
};

#endif // NXTCOMMUNICATOR_H
