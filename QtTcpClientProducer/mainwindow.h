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
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public:
    void timerEvent(QTimerEvent *event);

public slots:
  void tcpConnect();
  void putData();
  void tcpDisconnect();
  void setTiming();

private:
  int tempo = 1000; // tempo, em ms, do timing
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
