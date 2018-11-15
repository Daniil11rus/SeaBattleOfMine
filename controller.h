#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QPainter>
#include "model.h"
#include <QMainWindow>

class Controller
{
public:
    Controller() {}
    Controller(Model *model);
    ~Controller() {}
    void onMousePressed(const QPoint& pos, QMainWindow *w);
private:
    Model *model;
};

#endif // CONTROLLER_H
