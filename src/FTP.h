#ifndef FTP_H
#define FTP_H
#pragma once
#include "ui_FTP.h"
#include <QMainWindow>
#include "transhelper.h"
#include <thread>
class FTP : public QMainWindow {
    Q_OBJECT

private:
    Ui_FTP* ui;
    TransHelper * transHelper_;
public:
    FTP(QWidget* parent = nullptr);
    ~FTP();
signals:
    void fileSent(bool success);
    void fileRecv(bool success);
    void Sending(int value);
    void Recving(int value);
private slots:
    void on_SendBtn_clicked();
    void on_RecvBtn_clicked();
    void on_ChooseFileBtn_clicked();
private:
    void SendFileThread(QString port,QString fileName);
    void RecvFileThread(QString IP,QString port,QString fileName);
    void updateSendValue(int value);
    void updateRecvValue(int value);
};
#endif