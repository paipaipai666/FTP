#include "transhelper.h"
#include <cstring>
extern "C"{
#include <winsock2.h> 
#include <cstdio>
}
#pragma comment(lib, "lws2_32.lib")
TransHelper::TransHelper() {}
int TransHelper::SendFile(QString port,QString fileName){
    
    std::string SendPort = port.toStdString();
    std::string SendfileName = fileName.toStdString();

    WSADATA wsaData;
    SOCKET hServSock,hClntSock;
    FILE *fp;
    char buf[TransHelper::BUF_SIZE];
    int readCnt;

    SOCKADDR_IN servAdr,clntAdr;
    int clntAdrSz;

    if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
        return ErrorHandling("WSAStartup() error");

    fp=fopen(SendfileName.c_str(),"rb");
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

    char buf[BUF_SIZE];
    int readCnt;
    SOCKADDR_IN servAdr;

    if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
        return ErrorHandling("WSAStartup() error");

    fp=fopen(RecvFileName.c_str(),"wb");
    hSocket=socket(PF_INET,SOCK_STREAM,0);

    memset(&servAdr,0,sizeof(servAdr));
    servAdr.sin_family=AF_INET;
    servAdr.sin_addr.s_addr=inet_addr(RecvIP.c_str());
    servAdr.sin_port=htons(atoi(RecvPort.c_str()));

    connect(hSocket,(SOCKADDR*)&servAdr,sizeof(servAdr));

    while((readCnt=recv(hSocket,buf,BUF_SIZE,0))!=0)
        fwrite((void*)buf,1,readCnt,fp);

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
    fseek(fp,0,SEEK_END);
    size_t size = ftell(fp);
    return size;
}
