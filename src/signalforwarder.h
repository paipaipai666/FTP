#ifndef SIGNALFORWARDER_H
#define SIGNALFORWARDER_H
#pragma once
#include <QObject>

class SignalForwarder : public QObject
{
    Q_OBJECT
public:
    explicit SignalForwarder(QObject *parent = nullptr);
    void EmitSendChange(int value);
    void EmitRecvChange(int value);

signals:
    void SendValueChange(int value);
    void RecvValueChange(int value);   
};

#endif // SIGNALFORWARDER_H
