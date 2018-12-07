#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();


  //CONEXÕES
  connect(ui->pushButtonGet,
          SIGNAL(clicked(bool)),
          this,
          SLOT(getData()));


  //conecta a barra de ajuste do tempo com o valor apresentado dela ao lado.
  connect(ui->horizontalSlider_Timing,
          SIGNAL(valueChanged(int)),
          ui->label_timeChanging,
          SLOT(setNum(int)));


  //conecta o botão conecta com o tcpConnect()
  connect(ui->pushButton_Conectar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));

  //conecta o botão desconectar com o tcpDisconnect()
  connect(ui->pushButton_Desconectar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));

}

void MainWindow::tcpConnect(){
  socket->connectToHost(ui->lineEdit_recebeIP->text(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::tcpDisconnect()
{
    //existe o método void QAbstractSocket::disconnectFromHost()
    //pesquisar depois
    socket->disconnectFromHost();

}


void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      socket->write("get 127.0.0.1 5\r\n");
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          qDebug() << thetime << ": " << str;
        }
      }
    }
  }
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
