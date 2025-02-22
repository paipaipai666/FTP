#include "FTP.h"
#include <QFileDialog>
#include "transhelper.h"
#include <QMessageBox>

FTP::FTP(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_FTP)
{
    ui->setupUi(this);
}

FTP::~FTP()
{
    delete ui; 
}
void FTP::on_SendBtn_clicked()
{
    //QString IP = ui->IPlineEdit->text();
    QString port = ui->PortlineEditSend->text();
    QString fileName = ui->fileNamelineEditSend->text();
    if(TransHelper::SendFile(port,fileName)!=0)
	    QMessageBox::information(this, "警告", "文件发送失败！", QMessageBox::NoButton, QMessageBox::Close);
    else
        QMessageBox::information(this, "成功", "文件发送成功！", QMessageBox::NoButton, QMessageBox::Close);
}


void FTP::on_RecvBtn_clicked()
{
    QString IP = ui->IPlineEdit->text();
    QString port = ui->PortlineEditRecv->text();
    QString fileName = ui->fileNamelineEditRecv->text();
    if(TransHelper::RecvFile(IP,port,fileName)!=0)
        QMessageBox::information(this, "警告", "文件接收失败！", QMessageBox::NoButton, QMessageBox::Close);
    else
        QMessageBox::information(this, "成功", "文件接收成功！", QMessageBox::NoButton, QMessageBox::Close);
}


void FTP::on_ChooseFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),"F:",QStringLiteral("所有文件(*.*)"));
    ui->fileNamelineEditSend->setText(fileName);
}

