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


public:
    void timerEvent(QTimerEvent *event);



public slots:
    /**
   * @brief getData é responsável por recuperar os 10 últimos valores que o servidor recebeu, para um dado produtor.
   */
  void getData();
  /**
   * @brief tcpConnect é responsável por conectar o consumidor de dados ao socket do servidor.
   */
  void tcpConnect();
  /**
   * @brief tcpDisconnect é responsável por desconectar o consumidor de dados ao socket do servidor.
   */
  void tcpDisconnect();
  /**
   * @brief listarIP é responsável por listar os IPs que enviaram dados ao servidor.
   */
  void listarIP();
  /**
   * @brief atualizarIP é responsável por resgatar o IP selecionado.
   */
  void atualizarIP();
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


private:
  /**
   * @brief ui é um ponteiro para a interface do usuário.
   */
  Ui::MainWindow *ui;
  /**
   * @brief socket é a conexão realizada com o servidor.
   */
  QTcpSocket *socket;
  /**
   * @brief ip_atual é a seleção realizada no ListWidget.
   */
  QListWidgetItem ip_atual;
  /**
   * @brief tempo registra o período de execução do loop timerEvent, em milissegundos.
   */
  int tempo = 1000; // tempo, em ms, do timing
  /**
   * @brief temporizador registra o ID relativo ao timerEvent em execução.
   */
  int temporizador; // guarda o timer em uso
  /**
   * @brief flagTemporizador guarda a informação que indica se algum timerEvent está executando.
   */
  bool flagTemporizador;    //identificador do meu timer (timer especifico (posso ter mais de um));
  /**
   * @brief dados lista os dados recebidos pela função getData.
   */
  QStringList dados;


};

#endif // MAINWINDOW_H
