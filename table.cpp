#include "table.h"
#include "defines.h"
#include "field.h"

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

    for (int i = 0; i < this->table.size(); ++i) // drawing only the table
    {
        painter.drawLine(this->table.at(i));
    }

    for (int i = 0; i < QUANT_CELLS; ++i) // drawing ships
    {
        QPoint centre;
        if (this->tableBegin == MY_P_BEGIN) {centre = getCentreOfMyCell(i);}
        else {centre = getCentreOfEnCell(i);}

        if (sField[i] == "1" && this->tableBegin == MY_P_BEGIN) // "1" != EMPTY
        {
                QRectF selectedCell(centre.x() - CELL_SIDE / 2,
                                    centre.y() - CELL_SIDE/ 2,
                                    CELL_SIDE, CELL_SIDE);
                painter.setBrush(Qt::NoBrush);
                QPen pen;
                pen.setWidth(6);
                painter.setPen(pen);
                painter.drawRect(selectedCell);
        }
        else if (sField[i] == "2")
        {
            QPen pen;
            painter.setPen(pen);
            painter.setBrush(Qt::black);
            painter.drawEllipse(centre, 10, 10);
        }
        else if (sField[i] == "3")
        {
            QRectF selectedCell(centre.x() - CELL_SIDE / 2,
                                centre.y() - CELL_SIDE/ 2,
                                CELL_SIDE, CELL_SIDE);
            painter.setBrush(Qt::NoBrush);
            QPen pen;
            pen.setWidth(6);
            painter.setPen(pen);
            painter.drawRect(selectedCell);
            painter.drawLine(centre.x() - CELL_SIDE / 2,
                             centre.y() - CELL_SIDE / 2,
                             centre.x() + CELL_SIDE / 2,
                             centre.y() + CELL_SIDE / 2);
            painter.drawLine(centre.x() - CELL_SIDE / 2,
                             centre.y() + CELL_SIDE / 2,
                             centre.x() + CELL_SIDE / 2,
                             centre.y() - CELL_SIDE / 2);
        }
    }

    for (int i = 0; i < 10; ++i) // drawing vertical numbers
    {
        QPoint ofText(this->tableBegin.x() - CELL_SIDE / 2,
                      this->tableBegin.y() + CELL_SIDE * (0.5 + i) + TEXT_CORRECTOR);
        QString tNum = QString::number(i + 1);
        painter.drawText(ofText, tNum);
    }

    for (int i = 0; i < 10; ++i) // drawing horizontal letters
    {
        QPoint ofText(this->tableBegin.x() + CELL_SIDE * (0.5 + i) - TEXT_CORRECTOR,
                      this->tableBegin.y() - CELL_SIDE / 2 + 2 * TEXT_CORRECTOR);
        QString ch(65 + i);
        painter.drawText(ofText, ch);
    }
}

Table::Table()
{
}

Table::Table(int cellSide, QPoint tableBegin)
{
    this->cellSide = cellSide;
    this->tableBegin = tableBegin;
}
