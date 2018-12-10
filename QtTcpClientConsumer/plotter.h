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
    QStringList pontos;
signals:

public slots:
     /**
     * @brief atualizaPontos é o método responsável por atualizar a lista de pontos definida na variável pontos.
     */
    void atualizaPontos(QStringList novosPontos);
};

#endif // PLOTTER_H
