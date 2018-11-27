#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT      //compilador QT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public:
    void timerEvent(QTimerEvent *event);

public slots:       //slots = funções que promovem eventos uma vez que um dado SIGNAL é efetuado (APAGAR COMENTÁRIO DPS)
  void tcpConnect();
  void putData();
  void tcpDisconnect();
  void setTiming();

private:
  int tempo = 1000; // tempo, em ms, do timing
  int temporizador; // guarda o timer em uso
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
