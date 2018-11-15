#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include "defines.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QObject>

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->moveToCenter();
    model = new Model;
    model->setState(SETTING);
    controller = new Controller(model);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    Table myTable;
    Table enTable;
    QPoint my_pBegin(MY_PX_BEGIN, MY_PY_BEGIN);
    QPoint en_pBegin (EN_PX_BEGIN, EN_PY_BEGIN);

    myTable.setTableBegin(my_pBegin);
    myTable.setTableCellSide(CELL_SIDE);
    enTable.setTableBegin(en_pBegin);
    enTable.setTableCellSide(CELL_SIDE);

    myTable.tableDefine();
    enTable.tableDefine();

    QString sMyField = model->getMyField();
    QString sEnField = model->getEnField();
    myTable.drawTable(this, sMyField);
    enTable.drawTable(this, sEnField);
}

MainWindow::~MainWindow()
{
    delete ui;
}
