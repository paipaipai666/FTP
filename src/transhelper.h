#ifndef TRANSHELPER_H
#define TRANSHELPER_H
#pragma once
#include <QString>
#include "signalforwarder.h"
class TransHelper
{
public:
    TransHelper(SignalForwarder * signaller = nullptr){};
    int static ErrorHandling(const char* message);
    int static SendFile(QString port,QString fileName);
    int static RecvFile(QString IP,QString port,QString fileName);
    size_t static getFileSize(FILE * fp);
private:
    const int static BUF_SIZE=30;
    static SignalForwarder * signaller_;
    void static EmitSendValue(int value);
    void static EmitRecvChange(int value);
};



#endif // TRANSHELPER_H
