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
};

#endif // PLOTTER_H
