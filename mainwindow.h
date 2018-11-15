#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void moveToCenter();

protected:
    virtual void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
    State *state;
    Model *model;
    Controller *controller;
};

#endif // MAINWINDOW_H
