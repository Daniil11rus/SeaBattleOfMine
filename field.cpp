#include "field.h"
#include "defines.h"

Field::Field()
{
    cells.fill(EMPTY, QUANT_CELLS);
}

QString Field::getField()
{
    QString sField;

    for (QVector<Cell>::Iterator i = this->cells.begin();
         i != this->cells.end(); ++i)
    {
        if (*i == EMPTY)
        {
            sField += "0";
        }
        else if (*i == SHIP)
        {
            sField += "1";
        }
        else if (*i == MISS)
        {
            sField += "2";
        }
        else if (*i == DEST_SHIP)
        {
            sField += "3";
        }
    }

    return sField;
}
void Field::setCell(int ind, Cell cell)
{
    cells[ind] = cell;
}
Cell Field::getCell(int ind)
{
    return cells.at(ind);
}

int findCellInMyField(QPoint pos)
{
    int line;
    int col;
    int ind;

    line = (pos.y() - MY_PY_BEGIN) / CELL_SIDE + 1;
    col = (pos.x() - MY_PX_BEGIN) / CELL_SIDE + 1;
    ind = (line - 1) * 10 + col - 1;

    return ind;
}

int findCellInEnField(QPoint pos)
{
    int line;
    int col;
    int ind;

    line = (pos.y() - EN_PY_BEGIN) / CELL_SIDE + 1;
    col = (pos.x() - EN_PX_BEGIN) / CELL_SIDE + 1;
    ind = (line - 1) * 10 + col - 1;

    return ind;
}

void Field::fieldClear()
{
    this->cells.clear();
    this->cells.fill(EMPTY, QUANT_CELLS);
}

QPoint getCentreOfMyCell(int ind)
{
    int X = MY_PX_BEGIN + (ind - ind / 10 * 10) * CELL_SIDE + CELL_SIDE / 2;
    int Y = MY_PY_BEGIN + ind / 10 * CELL_SIDE + CELL_SIDE / 2;
    QPoint centre(X, Y);

    return centre;
}

QPoint getCentreOfEnCell(int ind)
{
    int X = EN_PX_BEGIN + (ind - ind / 10 * 10) * CELL_SIDE + CELL_SIDE / 2;
    int Y = EN_PY_BEGIN + ind / 10 * CELL_SIDE + CELL_SIDE / 2;
    QPoint centre(X, Y);

    return centre;
}
