#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    /**
     * @brief pontos recebe a lista de dados oriunda de QListWidget, na tela de usuário.
     */
    QList<int> pontos;
signals:

public slots:
     /**
     * @brief atualizaPontos é o método responsável por atualizar a lista de pontos definida na variável pontos.
     */
    void atualizaPontos(QList<int>  novosPontos);
    /**
     * @brief acharMax é responsável por descobrir o índice do maior número na lista de pontos.
     * @return o índice do maior valor.
     */
    int acharMax();
    /**
     * @brief acharMin é responsável por descobrir o índice do menor número na lista de pontos.
     * @return o índice do menor valor.
     */
    int acharMin();
};

#endif // PLOTTER_H
