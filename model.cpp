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

void Model::defineMyTable()
{
    this->myTable->tableDefine();
}

void Model::defineEnTable()
{
    this->enTable->tableDefine();
}

void Model::drawMyTable(QMainWindow *w)
{
    QString sMyField = this->getMyField();

    this->myTable->drawTable(w, sMyField);
}

void Model::drawEnTable(QMainWindow *w)
{
    QString sEnField = this->getEnField();

    this->enTable->drawTable(w, sEnField);
}

void Model::setMyBattleShip(int ind1, int ind2, int ind3, int ind4)
{
    BattleShip battleShip;
    battleShip.parts.insert(ind1, INTACT);
    battleShip.parts.insert(ind2, INTACT);
    battleShip.parts.insert(ind3, INTACT);
    battleShip.parts.insert(ind4, INTACT);
    this->myBattleShips.push_front(battleShip);
}

void Model::setMyCruiser(int ind1, int ind2, int ind3)
{
    Cruiser cruiser;
    cruiser.parts.insert(ind1, INTACT);
    cruiser.parts.insert(ind2, INTACT);
    cruiser.parts.insert(ind3, INTACT);
    this->myCruisers.push_front(cruiser);
}

void Model::setMyDestroyer(int ind1, int ind2)
{
    Destroyer destroyer;
    destroyer.parts.insert(ind1, INTACT);
    destroyer.parts.insert(ind2, INTACT);
    this->myDestroyers.push_front(destroyer);
}

void Model::setMyBoat(int ind1)
{
    Boat boat;
    boat.parts.insert(ind1, INTACT);
    this->myBoats.push_front(boat);
}

int Model::getQuantOfMyBS()
{
    return (this->myBattleShips.size());
}

int Model::getQuantOfMyCruisers()
{
    return (this->myCruisers.size());
}

int Model::getQuantOfMyDestroyers()
{
    return (this->myDestroyers.size());
}

int Model::getQuantOfMyBoats()
{
    return (this->myBoats.size());
}

void Model::cleanMyField()
{
    this->myBattleShips.clear();
    this->myCruisers.clear();
    this->myDestroyers.clear();
    this->myBoats.clear();
    this->myField->fieldClear();
}

void Model::setCellInEnField(int ind, Cell cell)
{
    this->enField->setCell(ind, cell);
}

void Model::fillEnField()
{
    srand(time(nullptr));

    int randInd = 0 + rand() % 96;
    bool HorOrVert = 0 + rand() % 2;
    QString sEnField = this->getEnField();

    if (HorOrVert && randInd - randInd / 10 * 10 < 7) // setting battle ship
    {
        BattleShip battleShip(randInd, randInd + 1, randInd + 2, randInd + 3);
        this->enBattleShips.push_front(battleShip);

        this->setCellInEnField(randInd, SHIP);
        this->setCellInEnField(randInd + 1, SHIP);
        this->setCellInEnField(randInd + 2, SHIP);
        this->setCellInEnField(randInd + 3, SHIP);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 4 + (i - 1) * CELL_ON_SIDE; ++j)
            {
                if (j >= 0 && j < 100)
                {
                    sEnField[j] = '2';
                }
            }
        }
    }
    else
    {
        int ind1;
        int ind2;
        int ind3;
        int ind4;

        if (randInd < 70)
        {
            ind1 = randInd;
            ind2 = randInd + 1 * CELL_ON_SIDE;
            ind3 = randInd + 2 * CELL_ON_SIDE;
            ind4 = randInd + 3 * CELL_ON_SIDE;
        }
        else
        {
            ind1 = randInd;
            ind2 = randInd - 1 * CELL_ON_SIDE;
            ind3 = randInd - 2 * CELL_ON_SIDE;
            ind4 = randInd - 3 * CELL_ON_SIDE;
        }

        BattleShip battleShip(ind1, ind2, ind3, ind4);
        this->enBattleShips.push_front(battleShip);

        this->setCellInEnField(ind1, SHIP);
        this->setCellInEnField(ind2, SHIP);
        this->setCellInEnField(ind3, SHIP);
        this->setCellInEnField(ind4, SHIP);

        for (int i = 0; i < 6; ++i)
        {
            for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 1 + (i - 1) * CELL_ON_SIDE; ++j)
            {
                if (j >= 0 && j < 100)
                {
                    sEnField[j] = '2';
                }
            }
        }
    }

    for (int i = 0; i < 2; ++i) // setting cruisers
    {
        bool set = false;

        while(!set)
        {
            int ind1, ind2, ind3;
            randInd = 0 + rand() % 96;
            if (randInd < 80)
            {
                ind1 = randInd;
                ind2 = randInd + 1 * CELL_ON_SIDE;
                ind3 = randInd + 2 * CELL_ON_SIDE;
            }
            else
            {
                ind1 = randInd;
                ind2 = randInd - 1 * CELL_ON_SIDE;
                ind3 = randInd - 2 * CELL_ON_SIDE;
            }

            if (randInd - randInd / 10 * 10 < 8 && sEnField[randInd] == "0" &&
                    sEnField[randInd + 1] == "0" &&
                    sEnField[randInd + 2] == "0")
            {
                Cruiser cruiser(randInd, randInd + 1, randInd + 2);
                this->enCruisers.push_front(cruiser);

                this->setCellInEnField(randInd, SHIP);
                this->setCellInEnField(randInd + 1, SHIP);
                this->setCellInEnField(randInd + 2, SHIP);

                for (int i = 0; i < 3; ++i)
                {
                    for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 3 + (i - 1) * CELL_ON_SIDE; ++j)
                    {
                        if (j >= 0 && j < 100)
                        {
                            sEnField[j] = '2';
                        }
                    }
                }

                set = true;
            }
            else if (randInd - randInd / 10 * 10 >= 8 &&
                     sEnField[ind1] == "0" &&
                     sEnField[ind2] == "0" &&
                     sEnField[ind3] == "0")
            {
                Cruiser cruiser(ind1, ind2, ind3);
                this->enCruisers.push_front(cruiser);

                this->setCellInEnField(ind1, SHIP);
                this->setCellInEnField(ind2, SHIP);
                this->setCellInEnField(ind3, SHIP);

                for (int i = 0; i < 5; ++i)
                {
                    for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 1 + (i - 1) * CELL_ON_SIDE; ++j)
                    {
                        if (j >= 0 && j < 100)
                        {
                            sEnField[j] = '2';
                        }
                    }
                }

                set = true;
            }
        }
    }

    for (int i = 0; i < 3; ++i) // setting destroyers
    {
        bool set = false;

        while(!set)
        {
            randInd = 0 + rand() % 96;
            int ind1, ind2;
            if (randInd < 90)
            {
                ind1 = randInd;
                ind2 = randInd + 1 * CELL_ON_SIDE;
            }
            else
            {
                ind1 = randInd;
                ind2 = randInd - 1 * CELL_ON_SIDE;
            }

            if (randInd - randInd / 10 * 10 < 8 && sEnField[randInd] == "0" &&
                    sEnField[randInd + 1] == "0")
            {
                Destroyer destroyer(randInd, randInd + 1);
                this->enDestroyers.push_front(destroyer);

                this->setCellInEnField(randInd, SHIP);
                this->setCellInEnField(randInd + 1, SHIP);

                for (int i = 0; i < 3; ++i)
                {
                    for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 2 + (i - 1) * CELL_ON_SIDE; ++j)
                    {
                        if (j >= 0 && j < 100)
                        {
                            sEnField[j] = '2';
                        }
                    }
                }

                set = true;
            }
            else if (randInd - randInd / 10 * 10 >= 8 &&
                     sEnField[ind1] == "0" &&
                     sEnField[ind2] == "0")
            {
                Destroyer destroyer(ind1, ind2);
                this->enDestroyers.push_front(destroyer);

                this->setCellInEnField(ind1, SHIP);
                this->setCellInEnField(ind2, SHIP);

                for (int i = 0; i < 4; ++i)
                {
                    for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 1 + (i - 1) * CELL_ON_SIDE; ++j)
                    {
                        if (j >= 0 && j < 100)
                        {
                            sEnField[j] = '2';
                        }
                    }
                }

                set = true;
            }
        }
    }

    for (int i = 0; i < 4; ++i) // setting boats
    {
        bool set = false;

        while(!set)
        {
            randInd = 0 + rand() % 96;

            if (sEnField[randInd] == "0")
            {
                Boat boat(randInd);
                this->enBoats.push_front(boat);

                this->setCellInEnField(randInd, SHIP);

                for (int i = 0; i < 3; ++i)
                {
                    for (int j = randInd - 1 + (i - 1) * CELL_ON_SIDE; j <= randInd + 1 + (i - 1) * CELL_ON_SIDE; ++j)
                    {
                        if (j >= 0 && j < 100)
                        {
                            sEnField[j] = '2';
                        }
                    }
                }

                set = true;
            }
        }
    }
}

Cell Model::getCellInEnField(int ind)
{
    return (this->enField->getCell(ind));
}

int Model::getQuantOfEnBS()
{
    return (this->enBattleShips.size());
}

int Model::getQuantOfEnCruisers()
{
    return (this->enCruisers.size());
}

int Model::getQuantOfEnDestroyers()
{
    return (this->enDestroyers.size());
}

int Model::getQuantOfEnBoats()
{
    return (this->enBoats.size());
}

Model::Model()
{
    this->myField = new Field();
    this->enField = new Field();
    this->myTable = new Table(CELL_SIDE, MY_P_BEGIN);
    this->enTable = new Table(CELL_SIDE, EN_P_BEGIN);
    this->state = SETTING;
}

Model::~Model()
{
    delete enField;
    delete myField;
    delete enTable;
    delete myTable;
}
