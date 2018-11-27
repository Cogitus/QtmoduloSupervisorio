/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonPut;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_IPdigitar;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Conectar;
    QPushButton *pushButton_Desconectar;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_MIN;
    QSlider *horizontalSlider_Maximo;
    QLCDNumber *lcdNumber_Maximo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_MAX;
    QSlider *horizontalSlider_Minimo;
    QLCDNumber *lcdNumber_Minimo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Timing;
    QSlider *horizontalSlider_Timing;
    QLabel *label_ShowTiming;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_IniciarTransmissao;
    QPushButton *pushButton_InterromperTransmissao;
    QTextBrowser *textBrowser_Dados;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(487, 315);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonPut = new QPushButton(centralWidget);
        pushButtonPut->setObjectName(QStringLiteral("pushButtonPut"));
        pushButtonPut->setGeometry(QRect(10, 220, 101, 29));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 453, 194));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_IPdigitar = new QLineEdit(widget);
        lineEdit_IPdigitar->setObjectName(QStringLiteral("lineEdit_IPdigitar"));

        verticalLayout->addWidget(lineEdit_IPdigitar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Conectar = new QPushButton(widget);
        pushButton_Conectar->setObjectName(QStringLiteral("pushButton_Conectar"));

        horizontalLayout->addWidget(pushButton_Conectar);

        pushButton_Desconectar = new QPushButton(widget);
        pushButton_Desconectar->setObjectName(QStringLiteral("pushButton_Desconectar"));

        horizontalLayout->addWidget(pushButton_Desconectar);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_MIN = new QLabel(widget);
        label_MIN->setObjectName(QStringLiteral("label_MIN"));

        horizontalLayout_3->addWidget(label_MIN);

        horizontalSlider_Maximo = new QSlider(widget);
        horizontalSlider_Maximo->setObjectName(QStringLiteral("horizontalSlider_Maximo"));
        horizontalSlider_Maximo->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_Maximo);

        lcdNumber_Maximo = new QLCDNumber(widget);
        lcdNumber_Maximo->setObjectName(QStringLiteral("lcdNumber_Maximo"));
        lcdNumber_Maximo->setFrameShadow(QFrame::Plain);
        lcdNumber_Maximo->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcdNumber_Maximo);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_MAX = new QLabel(widget);
        label_MAX->setObjectName(QStringLiteral("label_MAX"));

        horizontalLayout_2->addWidget(label_MAX);

        horizontalSlider_Minimo = new QSlider(widget);
        horizontalSlider_Minimo->setObjectName(QStringLiteral("horizontalSlider_Minimo"));
        horizontalSlider_Minimo->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_Minimo);

        lcdNumber_Minimo = new QLCDNumber(widget);
        lcdNumber_Minimo->setObjectName(QStringLiteral("lcdNumber_Minimo"));
        lcdNumber_Minimo->setFrameShape(QFrame::Box);
        lcdNumber_Minimo->setFrameShadow(QFrame::Plain);
        lcdNumber_Minimo->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(lcdNumber_Minimo);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Timing = new QLabel(widget);
        label_Timing->setObjectName(QStringLiteral("label_Timing"));

        horizontalLayout_4->addWidget(label_Timing);

        horizontalSlider_Timing = new QSlider(widget);
        horizontalSlider_Timing->setObjectName(QStringLiteral("horizontalSlider_Timing"));
        horizontalSlider_Timing->setMinimum(1);
        horizontalSlider_Timing->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_Timing);

        label_ShowTiming = new QLabel(widget);
        label_ShowTiming->setObjectName(QStringLiteral("label_ShowTiming"));

        horizontalLayout_4->addWidget(label_ShowTiming);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_IniciarTransmissao = new QPushButton(widget);
        pushButton_IniciarTransmissao->setObjectName(QStringLiteral("pushButton_IniciarTransmissao"));

        horizontalLayout_5->addWidget(pushButton_IniciarTransmissao);

        pushButton_InterromperTransmissao = new QPushButton(widget);
        pushButton_InterromperTransmissao->setObjectName(QStringLiteral("pushButton_InterromperTransmissao"));

        horizontalLayout_5->addWidget(pushButton_InterromperTransmissao);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_3);

        textBrowser_Dados = new QTextBrowser(widget);
        textBrowser_Dados->setObjectName(QStringLiteral("textBrowser_Dados"));

        horizontalLayout_6->addWidget(textBrowser_Dados);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 487, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonPut->setText(QApplication::translate("MainWindow", "putData", nullptr));
        pushButton_Conectar->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
        pushButton_Desconectar->setText(QApplication::translate("MainWindow", "Desconectar", nullptr));
        label_MIN->setText(QApplication::translate("MainWindow", "MIN", nullptr));
        label_MAX->setText(QApplication::translate("MainWindow", "MAX", nullptr));
        label_Timing->setText(QApplication::translate("MainWindow", "Timing(s)", nullptr));
        label_ShowTiming->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_IniciarTransmissao->setText(QApplication::translate("MainWindow", "Iniciar", nullptr));
        pushButton_InterromperTransmissao->setText(QApplication::translate("MainWindow", "Interromper", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
