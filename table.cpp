#include <table.h>
#include "defines.h"
#include <field.h>

void Table::setTableCellSide(int cellSide)
{
    this->cellSide = cellSide;
}

void Table::setTableBegin(QPoint tableBegin)
{
    this->tableBegin = tableBegin;
}

int Table::getTableCellSide()
{
    return this->cellSide;
}


QPoint Table::getTableBegin()
{
    return this->tableBegin;
}

void Table::tableDefine()
{
    int quantCellsSide = QUANT_CELLS / 10;
    int tableSide = quantCellsSide * this->cellSide; // 10 is just a quantity of cells on a one
                                                        // table side

    for (int i = 0; i < (quantCellsSide + 1); ++i) // horizontal
    {
        int yLine = this->getTableBegin().y() + i * this->cellSide;
        QPoint one(this->tableBegin.x(), yLine);
        QPoint two(this->tableBegin.x() + tableSide, yLine);
        QLine line(one, two);
        this->table.push_front(line);
    }

    for (int i = 0; i < (quantCellsSide + 1); ++i) // vertical
    {
        int xLine = this->getTableBegin().x() + i * this->cellSide;
        QPoint one(xLine, this->tableBegin.y());
        QPoint two(xLine, this->tableBegin.y() + tableSide);
        QLine line(one, two);
        this->table.push_front(line);
    }
}

void Table::drawTable(QMainWindow *w, QString sField)
{
    QPainter painter(w);

    for (int i = 0; i < this->table.size(); ++i)
    {
        painter.drawLine(this->table.at(i));
    }

    for (int i = 0; i < QUANT_CELLS; ++i)
    {
        if (sField[i] == "1") // "1" != EMPTY
        {
            QPoint centre = getCentreOfCell(i);

            QRectF selectedCell(centre.x() - CELL_SIDE / 2, centre.y() - CELL_SIDE/ 2,
                                CELL_SIDE, CELL_SIDE);
            painter.drawRect(selectedCell);
            painter.fillRect(selectedCell, Qt::black);
        }
    }
}
