#include "signalforwarder.h"

SignalForwarder::SignalForwarder(QObject *parent)
    : QObject{parent}
{}

void SignalForwarder::EmitSendChange(int value){
    emit SendValueChange(value);
}

void SignalForwarder::EmitRecvChange(int value){
    emit RecvValueChange(value);
}
