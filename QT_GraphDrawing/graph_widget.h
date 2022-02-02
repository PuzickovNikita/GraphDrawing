#ifndef GRAPH_WIDGET_H
#define GRAPH_WIDGET_H

#include <QObject>
#include <QWidget>

#include "../Graph.h"

class Graph_Widget : public QWidget
{
    Q_OBJECT

    Graph graph;
public:
    explicit Graph_Widget(QWidget *parent = nullptr);

signals:

};

#endif // GRAPH_WIDGET_H
