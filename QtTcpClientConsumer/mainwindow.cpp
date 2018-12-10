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
          this,
          SLOT(setTiming()));


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

  //conecta o botão  ui->pushButton_atualizarIPs com o SLOT listarIP
  connect(ui->pushButton_atualizarIPs,
          SIGNAL(clicked(bool)),
          this,
          SLOT(listarIP()));

  //conecta o ato de clicar em um item no ui->listWidget_lPs, coma a atualização do ip_atual
  connect(ui->listWidget_lPs,
          SIGNAL(itemSelectionChanged()),
          this,
          SLOT(atualizarIP()));

  //conecta o ui->pushButtom_IniciaTransmissao
  connect(ui->pushButton_Iniciar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(reviveTemporizador()));


  //conecta o ui->pushButtom_InterromperTransmissao
  connect(ui->pushButton_Interromper,
          SIGNAL(clicked(bool)),
          this,
          SLOT(mataTemporizador()));

}



//Ações do temporizador.
void MainWindow::mataTemporizador()
{
    if (flagTemporizador == true) {
        killTimer(temporizador);
        flagTemporizador = false;
    }
}


void MainWindow::reviveTemporizador()
{

    if(flagTemporizador == false) {
        temporizador = startTimer(tempo);
        flagTemporizador = true;
    }
}


void MainWindow::setTiming(){
    // atualização do tempo, no sistema
    tempo = ui->horizontalSlider_Timing->value()*100; // tempo, em ms

    if (flagTemporizador) {
        killTimer(temporizador);
        temporizador = startTimer(tempo);
    }

    //atualização da label responsável por mostrar o timing em segundos
    QString valor = QString::number(ui->horizontalSlider_Timing->value());
    ui->label_timeChanging->setText(valor); // devo passar o valor do horizontalSliderTiming

}



//OUTRAS FUNÇÕES NÃO HERDADAS
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
      QString comando = "get " + ip_atual.text() + " 5\r\n"  ;
      qDebug() << "reading..."; //toStdString().c_str()
      socket->write(comando.toStdString().c_str());
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



void MainWindow::listarIP(){
    QString str;
    QStringList list;
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
      if(socket->isOpen()){
        qDebug() << "reading...";
        socket->write("list");
        socket->waitForBytesWritten();
        socket->waitForReadyRead();
        qDebug() << socket->bytesAvailable();
        ui->listWidget_lPs->clear();
        while(socket->bytesAvailable()){
          str = socket->readLine().replace("\n","").replace("\r","");
          ui->listWidget_lPs->addItem(str);
          qDebug() <<"IPS recebebidos: "<< str;
        }
      }
    }
}



// pesquisar o signal "item activated", a ser usado no if antes do botão "atualizar"
void MainWindow::atualizarIP(){
    QListWidgetItem* ponteiro_atual = ui->listWidget_lPs->currentItem();
    ip_atual = *ponteiro_atual;
    qDebug() << "clicaou-se no item "<< ip_atual.text();
}



void MainWindow::timerEvent(QTimerEvent *event)
{
    getData();
    //qDebug() << dado;             aqui queremos printar os dados recebidos.
}



MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
