#include "controller.h"
#include "defines.h"
#include "mainwindow.h"
#include "used_libraries.h"

Controller::Controller(Model *model)
{
    this->model = model;
}

void Controller::closeTheWindow(QMainWindow *w)
{
    w->close();
}

void Controller::checkGameEnd(QMainWindow *w)
{
    QString sMyField = this->model->getMyField();
    int quantOfMyDestCells = 0;

    for (int i = 0; i < 100; ++i)
    {
        if (sMyField[i] == '3')
        {
            ++quantOfMyDestCells;
        }
    }

    if (quantOfMyDestCells == 20)
    {
        QMessageBox msg;
        msg.setText("You are a loser!");
        msg.show();
        msg.exec();
        this->closeTheWindow(w);
    }

    QString sEnField = this->model->getEnField();
    int quantOfEnDestCells = 0;

    for (int i = 0; i < 100; ++i)
    {
        if (sEnField[i] == '3')
        {
            ++quantOfEnDestCells;
        }
    }

    if (quantOfEnDestCells == 20)
    {
        QMessageBox msg;
        msg.setText("You are a winner!");
        msg.show();
        msg.exec();
        this->closeTheWindow(w);
    }
}

void Controller::enTurn(QMainWindow *w)
{
    bool set = false;

    while (set == false)
    {
        int randInd = 0 + rand() % 100;

        if (this->model->getCellInMyField(randInd) != DEST_SHIP &&
                this->model->getCellInMyField(randInd) != MISS)
        {
            if (this->model->getCellInMyField(randInd) == EMPTY)
            {
                this->model->setCellInMyField(randInd, MISS);
            }
            else
            {
                this->model->setCellInMyField(randInd, DEST_SHIP);

                this->checkGameEnd(w);
            }

            set = true;
        }
    }

    this->model->setState(MY_TURN);
}

void Controller::onMousePressed(const QPoint& pos, QMainWindow *w)
{
    if (model->getState() == SETTING &&
            pos.x() >= MY_PX_BEGIN &&
            pos.x() <= (MY_PX_BEGIN + TABLE_SIDE) &&
            pos.y() >= MY_PY_BEGIN &&
            pos.y() <= (MY_PY_BEGIN + TABLE_SIDE))
    {
        int indOfPressedCell = findCellInMyField(pos);

        if (model->getCellInMyField(indOfPressedCell) == EMPTY)
        {
            model->setCellInMyField(indOfPressedCell, SHIP);

            w->update();
        }
    }

    if (model->getState() == MY_TURN &&
            pos.x() >= EN_PX_BEGIN &&
            pos.x() <= (EN_PX_BEGIN + TABLE_SIDE) &&
            pos.y() >= EN_PY_BEGIN &&
            pos.y() <= (EN_PY_BEGIN + TABLE_SIDE))
    {
        int indOfPressedCell = findCellInEnField(pos);

        if (model->getCellInEnField(indOfPressedCell) == EMPTY)
        {
            model->setCellInEnField(indOfPressedCell, MISS);

            w->update();

            this->model->setState(EN_TURN);
            this->enTurn(w);
        }
        else if (model->getCellInEnField(indOfPressedCell) == SHIP)
        {
            model->setCellInEnField(indOfPressedCell, DEST_SHIP);

            w->update();

            this->checkGameEnd(w);

            this->model->setState(EN_TURN);
            this->enTurn(w);
        }
    }
}

void Controller::onButtonSetClicked(QMainWindow *w, QPushButton *buttonSet)
{
    QString sMyField = this->model->getMyField();

    for (int i = 0; i < LINES; ++i) // finding horizontal battleships
    {
        for (int j = 1; j < COLUMNS - 2; ++j)
        {
            int ind1 = i * CELL_ON_SIDE + j;
            int ind2 = i * CELL_ON_SIDE + j - 1;
            int ind3 = i * CELL_ON_SIDE + j + 1;
            int ind4 = i * CELL_ON_SIDE + j + 2;

            if (sMyField.at(ind1) == "1" &&
                    sMyField.at(ind2) == "1" &&
                    sMyField.at(ind3) == "1" &&
                    sMyField.at(ind4) == "1")
            {
                sMyField[ind1] = '2';
                sMyField[ind2] = '2';
                sMyField[ind3] = '2';
                sMyField[ind4] = '2';

                this->model->setMyBattleShip(ind1, ind2, ind3, ind4);
            }
        }
    }

    for (int i = 0; i < COLUMNS; ++i) // finding vertical battleships
    {
        for (int j = 1; j < LINES - 2; ++j)
        {
            int ind1 = j * CELL_ON_SIDE + i;
            int ind2 = j * CELL_ON_SIDE + i - 1 * CELL_ON_SIDE;
            int ind3 = j * CELL_ON_SIDE + i + 1 * CELL_ON_SIDE;
            int ind4 = j * CELL_ON_SIDE + i + 2 * CELL_ON_SIDE;

            if (sMyField.at(ind1) == "1" &&
                    sMyField.at(ind2) == "1" &&
                    sMyField.at(ind3) == "1" &&
                    sMyField.at(ind4) == "1")
            {
                sMyField[ind1] = '2';
                sMyField[ind2] = '2';
                sMyField[ind3] = '2';
                sMyField[ind4] = '2';

                this->model->setMyBattleShip(ind1, ind2, ind3, ind4);
            }
        }
    }

    for (int i = 0; i < LINES; ++i) // finding horizontal cruisers
    {
        for (int j = 1; j < COLUMNS - 1; ++j)
        {
            int ind1 = i * CELL_ON_SIDE + j;
            int ind2 = i * CELL_ON_SIDE + j - 1;
            int ind3 = i * CELL_ON_SIDE + j + 1;

            if (sMyField.at(ind1) == "1" &&
                    sMyField.at(ind2) == "1" &&
                    sMyField.at(ind3) == "1")
            {
                sMyField[ind1] = '2';
                sMyField[ind2] = '2';
                sMyField[ind3] = '2';

                this->model->setMyCruiser(ind1, ind2, ind3);
            }
        }
    }

    for (int i = 0; i < COLUMNS; ++i) // finding vertical cruisers
    {
        for (int j = 1; j < LINES - 1; ++j)
        {
            int ind1 = j * CELL_ON_SIDE + i;
            int ind2 = j * CELL_ON_SIDE + i - 1 * CELL_ON_SIDE;
            int ind3 = j * CELL_ON_SIDE + i + 1 * CELL_ON_SIDE;

            if (sMyField.at(ind1) == "1" &&
                    sMyField.at(ind2) == "1" &&
                    sMyField.at(ind3) == "1")
            {
                sMyField[ind1] = '2';
                sMyField[ind2] = '2';
                sMyField[ind3] = '2';

                this->model->setMyCruiser(ind1, ind2, ind3);
            }
        }
    }

    for (int i = 0; i < LINES; ++i) // finding horizontal destroyers
    {
        for (int j = 0; j < COLUMNS - 1; ++j)
        {
            int ind1 = i * CELL_ON_SIDE + j;
            int ind2 = i * CELL_ON_SIDE + j + 1;

            if (sMyField.at(ind1) == "1" &&
                    sMyField.at(ind2) == "1")
            {
                sMyField[ind1] = '2';
                sMyField[ind2] = '2';

                this->model->setMyDestroyer(ind1, ind2);
            }
        }
    }

    for (int i = 0; i < COLUMNS; ++i) // finding vertical destroyers
    {
        for (int j = 0; j < LINES - 1; ++j)
        {
            int ind1 = j * CELL_ON_SIDE + i;
            int ind2 = j * CELL_ON_SIDE + i + 1 * CELL_ON_SIDE;

            if (sMyField.at(ind1) == "1" &&
                    sMyField.at(ind2) == "1")
            {
                sMyField[ind1] = '2';
                sMyField[ind2] = '2';

                this->model->setMyDestroyer(ind1, ind2);
            }
        }
    }

    for (int i = 0; i < LINES; ++i) // finding boats
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            int ind1 = i * CELL_ON_SIDE + j;

            if (sMyField.at(ind1) == "1")
            {
                this->model->setMyBoat(ind1);
            }
        }
    }

//    QMessageBox msg;
//    QString str1 = QString::number(this->model->getQuantOfMyBS());
//    QString str2 = QString::number(this->model->getQuantOfMyCruisers());
//    QString str3 = QString::number(this->model->getQuantOfMyDestroyers());
//    QString str4 = QString::number(this->model->getQuantOfMyBoats());
//    msg.setText(str1 + str2 + str3 + str4);
//    msg.show();
//    msg.exec();

    if (this->model->getQuantOfMyBS() == 1 &&
            this->model->getQuantOfMyCruisers() == 2 &&
            this->model->getQuantOfMyDestroyers() == 3 &&
            this->model->getQuantOfMyBoats() == 4)
    {
        buttonSet->close();
        this->model->setState(EN_TURN);
        this->model->fillEnField();
        this->enTurn(w);
        w->update();

//        QMessageBox msg;
//        msg.setText(this->model->getEnField());
//        msg.show();
//        msg.exec();
    }
    else
    {
        this->model->cleanMyField();
        w->update();
    }
}
