#ifndef TRANSHELPER_H
#define TRANSHELPER_H
#pragma once
#include <QString>
extern "C"{
    #include <winsock2.h> 
}
class TransHelper
{
private: 
    const int static BUF_SIZE=30;
public:
    TransHelper();
    int SendFile(QString port,QString fileName);
    int RecvFile(QString IP,QString port,QString fileName);
    size_t static getFileSize(FILE * fp);
    int static ErrorHandling(const char* message);
};

#endif 
