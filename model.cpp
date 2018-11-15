#include "model.h"
#include "mainwindow.h"
#include "defines.h"

Cell Model::getCellInMyField(int ind)
{
    Cell cell = this->myField->getCell(ind);

    return cell;
}

void Model::setCellInMyField(int ind, Cell cell)
{
    this->myField->setCell(ind, cell);
}

State Model::getState()
{
    return this->state;
}
void Model::setState(State state)
{
    this->state = state;
}

QString Model::getMyField()
{
    QString sMyField = this->myField->getField();

    return sMyField;
}

QString Model::getEnField()
{
    QString sEnField = this->enField->getField();

    return sEnField;
}

Model::Model()
{
    this->myField = new Field();
    this->enField = new Field();
}
