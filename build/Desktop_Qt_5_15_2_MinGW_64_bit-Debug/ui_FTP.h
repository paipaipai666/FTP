/********************************************************************************
** Form generated from reading UI file 'FTP.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTP_H
#define UI_FTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTP
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IPlineEdit;
    QLabel *label_2;
    QLineEdit *PortlineEditSend;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *fileNamelineEditSend;
    QPushButton *ChooseFileBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QProgressBar *progressBar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *PortlineEditRecv;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *fileNamelineEditRecv;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QProgressBar *progressBar_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *SendBtn;
    QPushButton *RecvBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FTP)
    {
        if (FTP->objectName().isEmpty())
            FTP->setObjectName(QString::fromUtf8("FTP"));
        FTP->resize(778, 551);
        centralwidget = new QWidget(FTP);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 50, 701, 451));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        IPlineEdit = new QLineEdit(widget);
        IPlineEdit->setObjectName(QString::fromUtf8("IPlineEdit"));

        horizontalLayout->addWidget(IPlineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        PortlineEditSend = new QLineEdit(widget);
        PortlineEditSend->setObjectName(QString::fromUtf8("PortlineEditSend"));

        horizontalLayout->addWidget(PortlineEditSend);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        fileNamelineEditSend = new QLineEdit(widget);
        fileNamelineEditSend->setObjectName(QString::fromUtf8("fileNamelineEditSend"));

        horizontalLayout_2->addWidget(fileNamelineEditSend);

        ChooseFileBtn = new QPushButton(widget);
        ChooseFileBtn->setObjectName(QString::fromUtf8("ChooseFileBtn"));

        horizontalLayout_2->addWidget(ChooseFileBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_3->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        PortlineEditRecv = new QLineEdit(widget);
        PortlineEditRecv->setObjectName(QString::fromUtf8("PortlineEditRecv"));

        horizontalLayout_4->addWidget(PortlineEditRecv);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        fileNamelineEditRecv = new QLineEdit(widget);
        fileNamelineEditRecv->setObjectName(QString::fromUtf8("fileNamelineEditRecv"));

        horizontalLayout_5->addWidget(fileNamelineEditRecv);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        progressBar_2 = new QProgressBar(widget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(0);

        horizontalLayout_6->addWidget(progressBar_2);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(217, 10, 301, 31));
        horizontalLayout_7 = new QHBoxLayout(widget1);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        SendBtn = new QPushButton(widget1);
        SendBtn->setObjectName(QString::fromUtf8("SendBtn"));

        horizontalLayout_7->addWidget(SendBtn);

        RecvBtn = new QPushButton(widget1);
        RecvBtn->setObjectName(QString::fromUtf8("RecvBtn"));

        horizontalLayout_7->addWidget(RecvBtn);

        FTP->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FTP);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FTP->setStatusBar(statusbar);

        retranslateUi(FTP);

        QMetaObject::connectSlotsByName(FTP);
    } // setupUi

    void retranslateUi(QMainWindow *FTP)
    {
        FTP->setWindowTitle(QCoreApplication::translate("FTP", "FTP", nullptr));
        label->setText(QCoreApplication::translate("FTP", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FTP", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FTP", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        ChooseFileBtn->setText(QCoreApplication::translate("FTP", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        label_4->setText(QCoreApplication::translate("FTP", "\344\274\240\350\276\223\350\277\233\345\272\246\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("FTP", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("FTP", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("FTP", "\346\216\245\346\224\266\350\277\233\345\272\246\357\274\232", nullptr));
        SendBtn->setText(QCoreApplication::translate("FTP", "\345\274\200\345\247\213\345\217\221\351\200\201", nullptr));
        RecvBtn->setText(QCoreApplication::translate("FTP", "\345\274\200\345\247\213\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTP: public Ui_FTP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTP_H
