#ifndef FIELD_H
#define FIELD_H

#include "used_libraries.h"

enum Cell
{
    EMPTY,
    MISS,
    SHIP,
    DEST_SHIP
};

int findCellInMyField(QPoint pos);
int findCellInEnField(QPoint pos);
QPoint getCentreOfMyCell(int ind);
QPoint getCentreOfEnCell(int ind);


class Field
{
private:
    QVector<Cell> cells;

public:
    Field();
    ~Field() {}
    void fieldClear();
    QString getField();
    void setCell(int ind, Cell cell);
    Cell getCell(int ind);
    int findCellInEnField(QPoint pos);
};

#endif // FIELD_H
