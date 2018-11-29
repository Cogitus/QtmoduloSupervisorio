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
    /**
   * @brief putData é o SLOT responsável por enviar as informações via socket.
   */
  void putData();
  /**
   * @brief tcpConnect é o SLOT responsável por conectar o programa ao servidor.
   */
  void tcpConnect();
  /**
   * @brief tcpDisconnect é o SLOT responsável por desconectar o programa ao servidor.
   */
  void tcpDisconnect();
  /**
   * @brief setTiming é o SLOT responsável por atualizar o valor do estado tempo e resetar o timerEvent relativo ao estado temporizador.
   */
  void setTiming();
  /**
   * @brief mataTemporizador é o SLOT responsável por parar a execução do SLOT timerEvent.
   */
  void mataTemporizador();
  /**
   * @brief reviveTemporizador é o SLOT responsável por iniciar a execução do SLOT timerEvent.
   */
  void reviveTemporizador();
  /**
   * @brief set_limiteMaximo é o SLOT responsável por atualizar o velor do estado limiteMáximo.
   */
  void set_limiteMaximo();
  /**
   * @brief set_limiteMinimo é o SLOT responsável por atualizar o velor do estado limiteMínimo.
   */
  void set_limiteMinimo();

private:
  /**
   * @brief tempo registra o período de execução do loop timerEvent, em milissegundos.
   */
  int tempo = 1000; // tempo, em ms, do timing
  /**
   * @brief temporizador registra o ID relativo ao timerEvent em execução.
   */
  int temporizador; // guarda o timer em uso
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  /**
   * @brief flagTemporizador guarda a informação que indica se algum timerEvent está executando.
   */
  bool flagTemporizador;    //identificador do meu timer (timer especifico (posso ter mais de um));
  /**
   * @brief limiteMinimo registra o limite mínimo do valor dos dados que serão enviados.
   */
  int limiteMinimo;         //limites dos números aleatórios gerados.
  /**
   * @brief limiteMaximo registra o limite máximo do valor dos dados que serão enviados.
   */
  int limiteMaximo;
  /**
   * @brief dado guarda a informação que será enviada via socket. Seu valor está limitado no intervalo [limiteMinimo, limiteMaximo].
   */
  QString dado;
};

#endif // MAINWINDOW_H
