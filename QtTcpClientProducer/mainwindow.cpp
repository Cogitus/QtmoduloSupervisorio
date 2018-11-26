#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();

  //inciando o Timer
  startTimer(50);     // 50-millisecond timer


  connect(ui->pushButtonPut,
          SIGNAL(clicked(bool)),
          this,
          SLOT(putData()));

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

  // conecta o ui->horizontalSlider_Minimo com o ui->lcdNumber_Minimo
  //ATENÇÃO! AINDA FALTA CONFIGURAR O VALOR MINIMO
  connect(ui->horizontalSlider_Minimo,
          SIGNAL(valueChanged(int)),
          ui->lcdNumber_Minimo,
          SLOT(display(int)));

  // conecta o ui->horizontalSlider_Timing com o ui->textBrowser_Timing
  connect(ui->horizontalSlider_Timing,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(setTiming()));
}

void MainWindow::tcpConnect(){
    //LINHA TESTE
    qDebug() << "CONECTADO";

    /* DESCOMENTAR, DEPOIS
  socket->connectToHost("127.0.0.1",1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
*/

}

void MainWindow::setTiming(){
    QString valor = QString::number(ui->horizontalSlider_Timing->value());
    ui->label_ShowTiming->setText(valor); // devo passar o valor do horizontalSliderTiming

}

void MainWindow::tcpDisconnect(){
    qDebug() << "DESCONECSAO ARRETADA";

    //existe o método void QAbstractSocket::disconnectFromHost()
    //pesquisar depois
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%35)+"\r\n";

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
    QString valor = QString::number(ui->horizontalSlider_Timing->value());
    ui->textBrowser_Dados->setText(valor);
}
