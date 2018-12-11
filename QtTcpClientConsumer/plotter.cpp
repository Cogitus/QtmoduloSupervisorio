#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{

}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    int indice_menor, indice_maior;
    float y_posterior, y_anterior;

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(58, 65, 136));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(1, 255, 132));
    pen.setWidth(1);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,width(),height());


    //parte visual do plotter em que geramos o quadriculado
    for(int i=width()/15; i<width(); i=i+width()/15){
        painter.drawLine(i, 0, i, height());
    }

    for(int i=height()/15; i<height(); i=i+height()/15){
        painter.drawLine(0, i, width(), i);
    }

    indice_maior = acharMax();
    indice_menor = acharMin();

}



int Plotter::acharMax()
{
    int index = 0;
    for(int i = 1; i<pontos.length()-1; i++){
        if(pontos.at(i) > pontos.at(i-1)){
            index = i;
        }
    }
    return index;
}

int Plotter::acharMin()
{
    int index = 0;
    for(int i = 1; i<pontos.length()-1; i++){
        if(pontos.at(i) < pontos.at(i-1)){
            index = i;
        }
    }
    return index;
}

void Plotter::atualizaPontos(QList<int>  novosPontos)
{
    pontos = novosPontos ;
    //qDebug() <<"chamou o atualizaPontos";
    repaint();
}

