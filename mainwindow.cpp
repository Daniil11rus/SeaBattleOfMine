#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include "defines.h"
#include "used_libraries.h"

void MainWindow::moveToCenter()
{
    this->setGeometry
    (
        QStyle::alignedRect
        (
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        QPoint pos = ev->pos();

        controller->onMousePressed(pos, this);
    }
    else
    {
        return;
    }
}

void MainWindow::setupGame()
{
    this->ui->setupUi(this);
    this->model = new Model;
    this->controller = new Controller(model);
    this->moveToCenter();
    this->buttonSet = new QPushButton("Set ships!", this);
    this->buttonSet->setGeometry(QRect(QPoint(100, 625), QSize(100, 50)));
    this->buttonSet->show();
    QObject::connect(buttonSet, SIGNAL(clicked()), this, SLOT(buttonSetClicked()));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    this->model->defineMyTable();
    this->model->defineEnTable();

    this->model->drawMyTable(this);
    this->model->drawEnTable(this);
}

void MainWindow::buttonSetClicked()
{
    this->controller->onButtonSetClicked(this, this->buttonSet);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setupGame();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete controller;
}
