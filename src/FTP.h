#ifndef FTP_H
#define FTP_H
#pragma once
#include "ui_FTP.h"
#include <QMainWindow>
#include "transhelper.h"

class FTP : public QMainWindow {
    Q_OBJECT
    
public:
    FTP(QWidget* parent = nullptr);
    ~FTP();

private slots:
    void on_SendBtn_clicked();

    void on_RecvBtn_clicked();

    void on_ChooseFileBtn_clicked();

private:
    Ui_FTP* ui;
};
#endif