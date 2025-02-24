#ifndef TRANSHELPER_H
#define TRANSHELPER_H
#pragma once
#include <QString>
class TransHelper
{
public:
    TransHelper();
    int static ErrorHandling(const char* message);
    int static SendFile(QString port,QString fileName);
    int static RecvFile(QString IP,QString port,QString fileName);
private:
    const int static BUF_SIZE=30;
};



#endif // TRANSHELPER_H
