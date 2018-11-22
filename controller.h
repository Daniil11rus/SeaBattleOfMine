#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "used_libraries.h"
#include "model.h"

class Controller
{
public:
    Controller() {}
    Controller(Model *model);
    ~Controller() {}
    void onMousePressed(const QPoint& pos, QMainWindow *w);
    void onButtonSetClicked(QMainWindow *w, QPushButton *buttonSet);
    void enTurn(QMainWindow *w);
    void checkGameEnd(QMainWindow *w);
    void closeTheWindow(QMainWindow *w);

private:
    Model *model;
};

#endif // CONTROLLER_H
