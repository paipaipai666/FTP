#include "transhelper.h"
#include "FTP.h"
#include <cstring>
#include <QObject>
extern "C"{
#include <winsock2.h> 
#include <cstdio>
}
#pragma comment(lib, "lws2_32.lib")
TransHelper::TransHelper(){};
int TransHelper::SendFile(QString port,QString fileName){
    
    std::string SendPort = port.toStdString();
    std::string SendfileName = fileName.toStdString();

    WSADATA wsaData;
    SOCKET hServSock,hClntSock;
    FILE *fp;
    long long fileSize;
    int value;
    char buf[TransHelper::BUF_SIZE];
    int readCnt;

    SOCKADDR_IN servAdr,clntAdr;
    int clntAdrSz;

    if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
        return ErrorHandling("WSAStartup() error");

    fp=fopen(SendfileName.c_str(),"rb");
    fileSize=(long long)getFileSize(fp);
    hServSock=socket(PF_INET,SOCK_STREAM,0);

    memset(&servAdr,0,sizeof(servAdr));
    servAdr.sin_family=AF_INET;
    servAdr.sin_addr.s_addr=htonl(INADDR_ANY);
    servAdr.sin_port=htons(atoi(SendPort.c_str()));

    bind(hServSock,(SOCKADDR*)&servAdr,sizeof(servAdr));
    listen(hServSock,5);

    clntAdrSz=sizeof(clntAdr);
    hClntSock=accept(hServSock,(SOCKADDR*)&clntAdr,&clntAdrSz);
    while(1){
        readCnt=fread((void*)buf,1,BUF_SIZE,fp);
        if(readCnt<BUF_SIZE){
            send(hClntSock,(char*)&buf,readCnt,0);
            break;
        }
        send(hClntSock,(char*)&buf,BUF_SIZE,0);
    }
    fclose(fp);
    closesocket(hClntSock);
    closesocket(hServSock);
    return 0;
}

int TransHelper::RecvFile(QString IP,QString port,QString fileName){
    std::string RecvIP=IP.toStdString();
    std::string RecvPort=port.toStdString();
    std::string RecvFileName=fileName.toStdString();

    WSADATA wsaData;
    SOCKET hSocket;
    FILE *fp;
    int fileSize,value;

    char buf[BUF_SIZE];
    int readCnt;
    SOCKADDR_IN servAdr;

    if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
        return ErrorHandling("WSAStartup() error");

    fp=fopen(RecvFileName.c_str(),"wb");
    fileSize=(int)getFileSize(fp);
    hSocket=socket(PF_INET,SOCK_STREAM,0);

    memset(&servAdr,0,sizeof(servAdr));
    servAdr.sin_family=AF_INET;
    servAdr.sin_addr.s_addr=inet_addr(RecvIP.c_str());
    servAdr.sin_port=htons(atoi(RecvPort.c_str()));

    connect(hSocket,(SOCKADDR*)&servAdr,sizeof(servAdr));

    while((readCnt=recv(hSocket,buf,BUF_SIZE,0))!=0){
        fwrite((void*)buf,1,readCnt,fp);
    }

    fclose(fp);
    closesocket(hSocket);
    WSACleanup();
    return 0;
}

int TransHelper::ErrorHandling(const char* message){
    fputs(message,stderr);
    fputc('\n',stderr);
    return 1;
}

size_t TransHelper::getFileSize(FILE * fp){
    long cur_offset=ftell(fp);
    fseek(fp,0,SEEK_END);
    size_t size = ftell(fp);
    fseek(fp,cur_offset,SEEK_SET);
    return size;
}