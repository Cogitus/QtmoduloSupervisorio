#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();


public slots:
  void getData();
  void tcpConnect();
  void tcpDisconnect();
  void listarIP();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString ip_produtor;


};

#endif // MAINWINDOW_H
