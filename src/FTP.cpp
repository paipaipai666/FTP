#include "FTP.h"
#include <QFileDialog>
#include "transhelper.h"
#include <QMessageBox>
#include <thread>
#include <functional>
#include <QDebug>

FTP::FTP(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_FTP)
    ,transHelper_(new TransHelper)
{
    ui->setupUi(this);
    connect(this, &FTP::fileSent, this, [this](bool success){
        if(success){
            QMessageBox::information(this, "成功", "文件发送成功！", QMessageBox::NoButton, QMessageBox::Close);
            
        }
        else{
            QMessageBox::information(this, "警告", "文件发送失败！", QMessageBox::NoButton, QMessageBox::Close);
            ui->SendprogressBar->setValue(0);
        }  
    });
    connect(this, &FTP::fileRecv, this, [this](bool success){
        if(success){
            QMessageBox::information(this, "成功", "文件接收成功！", QMessageBox::NoButton, QMessageBox::Close);
            
        }
        else{
            QMessageBox::information(this, "警告", "文件接收失败！", QMessageBox::NoButton, QMessageBox::Close);
            ui->SendprogressBar->setValue(0);
        }
    });
}

FTP::~FTP()
{
    delete ui; 
    delete transHelper_;
}

void FTP::SendFileThread(QString port,QString fileName)
{
    bool success = (transHelper_->SendFile(port, fileName) == 0);
    emit fileSent(success);
}

void FTP::RecvFileThread(QString IP,QString port,QString fileName)
{
    bool success = (transHelper_->RecvFile(IP,port, fileName) == 0);
    emit fileRecv(success);
}

void FTP::on_SendBtn_clicked()
{
    ui->SendprogressBar->setRange(0, 0);
    ui->SendprogressBar->setOrientation(Qt::Horizontal);
    std::thread hThread;
    QString port = ui->PortlineEditSend->text();
    QString fileName = ui->fileNamelineEditSend->text();
    hThread = std::thread(std::bind(&FTP::SendFileThread,this,port,fileName));
    hThread.detach();
}


void FTP::on_RecvBtn_clicked()
{
    ui->RecvprogressBar->setRange(0, 0);
    ui->RecvprogressBar->setOrientation(Qt::Horizontal);
    std::thread hThread;
    QString IP = ui->IPlineEdit->text();
    QString port = ui->PortlineEditRecv->text();
    QString fileName = ui->fileNamelineEditRecv->text();
    hThread = std::thread(std::bind(&FTP::RecvFileThread,this,IP,port,fileName));
    hThread.detach();
}


void FTP::on_ChooseFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),"F:",QStringLiteral("所有文件(*.*)"));
    ui->fileNamelineEditSend->setText(fileName);
}

void FTP::updateSendValue(int value){
    qDebug() << "update!in FTP" << value;
    ui->SendprogressBar->setValue(value);
}

void FTP::updateRecvValue(int value){
    ui->RecvprogressBar->setValue(value);
}
