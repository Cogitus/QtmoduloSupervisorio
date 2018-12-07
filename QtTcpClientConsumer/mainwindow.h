#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>
#include <QListWidgetItem>

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
  void atualizarIP();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QListWidgetItem* ip_atual;


};

#endif // MAINWINDOW_H
