#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){

  ui->setupUi(this);
  socket = new QTcpSocket(this);


  //iniciando os limites de envio
  limiteMinimo = 1;
  limiteMaximo = 3;


  // quando o pushButton_conectar for clicado, devemos conectar ao Servidor (incompleto)
  connect(ui->pushButton_Conectar,
          SIGNAL(clicked(bool)),
          this,                     //dado que o método está no escopo da MainWindow, essa linha está certa,né?
          SLOT(tcpConnect()));

  // quando o pushButton_conectar for clicado, devemos conectar ao Servidor (incompleto)
  connect(ui->pushButton_Desconectar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));

  // conecta o ui->horizontalSlider_Maximo com o ui->lcdNumber_Maximo
  //ATENÇÃO! AINDA FALTA CONFIGURAR O VALOR MAXIMO
  connect(ui->horizontalSlider_Maximo,
          SIGNAL(valueChanged(int)),
          ui->lcdNumber_Maximo,
          SLOT(display(int)));

  //conecta o ui->horizontalSlider_Maximo com o slot set_limiteMaximo
  connect(ui->horizontalSlider_Maximo,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(set_limiteMaximo()));

  // conecta o ui->horizontalSlider_Minimo com o ui->lcdNumber_Minimo
  //ATENÇÃO! AINDA FALTA CONFIGURAR O VALOR MINIMO
  connect(ui->horizontalSlider_Minimo,
          SIGNAL(valueChanged(int)),
          ui->lcdNumber_Minimo,
          SLOT(display(int)));

  //conecta o ui->horizontalSlider_Minimo com o slot set_limiteMinimo
  connect(ui->horizontalSlider_Minimo,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(set_limiteMinimo()));

  // conecta o ui->horizontalSlider_Timing com o ui->textBrowser_Timing
  connect(ui->horizontalSlider_Timing,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(setTiming()));

  //conecta o ui->pushButtom_IniciaTransmissao
  connect(ui->pushButton_IniciarTransmissao,
          SIGNAL(clicked(bool)),
          this,
          SLOT(reviveTemporizador()));

  //conecta o ui->pushButtom_InterromperTransmissao
  connect(ui->pushButton_InterromperTransmissao,
          SIGNAL(clicked(bool)),
          this,
          SLOT(mataTemporizador()));

}

void MainWindow::tcpConnect(){

  socket->connectToHost(ui->lineEdit_IPdigitar->text(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
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
    ui->label_ShowTiming->setText(valor); // devo passar o valor do horizontalSliderTiming

}

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

void MainWindow::set_limiteMaximo(){
    limiteMaximo = ui->horizontalSlider_Maximo->value();
    qDebug() <<" limite maximo = " << limiteMaximo;
}

void MainWindow::set_limiteMinimo(){
    limiteMinimo = ui->horizontalSlider_Minimo->value();
    qDebug() <<" limite minimo = " << limiteMinimo;
}


void MainWindow::tcpDisconnect(){
    //existe o método void QAbstractSocket::disconnectFromHost()
    //pesquisar depois
    socket->disconnectFromHost();
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state() == QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " + dado +"\r\n";
    ui->textBrowser_Dados->append(str);

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

MainWindow::~MainWindow(){
  delete socket;
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    dado = QString::number((qrand()%(limiteMaximo - limiteMinimo + 1)) + limiteMinimo);
    putData();
    qDebug() << dado ;
}

//num = (rand() % (upper – lower + 1)) + lower


