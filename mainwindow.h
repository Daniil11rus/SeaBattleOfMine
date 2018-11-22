#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "used_libraries.h"
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
    void setupGame();

public slots:
    void buttonSetClicked();

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
    QPushButton *buttonSet;
};

#endif // MAINWINDOW_H
