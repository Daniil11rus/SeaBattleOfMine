#ifndef TABLE_H
#define TABLE_H

#include <QPainter>
#include <QMainWindow>

class Table
{
private:
    QVector<QLine> table;
    int cellSide;
    QPoint tableBegin;

public:
    Table() {}
    Table(int cellSide, QPoint cellBegin);
    void setTableCellSide(int cellSide);
    void setTableBegin(QPoint cellBegin);
    int getTableCellSide();
    QPoint getTableBegin();
    void tableDefine();
    void drawTable(QMainWindow *w, QString sMyTable);
};

#endif // TABLE_H
