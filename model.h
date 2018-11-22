#ifndef MODEL_H
#define MODEL_H

#include "field.h"
#include "table.h"
#include "ships.h"

enum State
{
    SETTING,
    MY_TURN,
    EN_TURN
};

class Model
{
public:
    Model();
    ~Model();
    State getState();
    void setState(State state);
    QString getMyField();
    QString getEnField();
    void setCellInMyField(int ind, Cell cell);
    void setCellInEnField(int ind, Cell cell);
    Cell getCellInMyField(int ind);
    Cell getCellInEnField(int ind);
    void defineMyTable();
    void defineEnTable();
    void drawMyTable(QMainWindow *w);
    void drawEnTable(QMainWindow *w);
    void setMyBattleShip(int ind1, int ind2, int ind3, int ind4);
    void setMyCruiser(int ind1, int ind2, int ind3);
    void setMyDestroyer(int ind1, int ind2);
    void setMyBoat(int ind1);
    int getQuantOfMyBS();
    int getQuantOfMyCruisers();
    int getQuantOfMyDestroyers();
    int getQuantOfMyBoats();
    void cleanMyField();
    void fillEnField();
    int getQuantOfEnBS();
    int getQuantOfEnCruisers();
    int getQuantOfEnDestroyers();
    int getQuantOfEnBoats();

private:
    Field *myField;
    Field *enField;
    Table *myTable;
    Table *enTable;
    State state;
    QVector<BattleShip> myBattleShips;
    QVector<Cruiser> myCruisers;
    QVector<Destroyer> myDestroyers;
    QVector<Boat> myBoats;
    QVector<BattleShip> enBattleShips;
    QVector<Cruiser> enCruisers;
    QVector<Destroyer> enDestroyers;
    QVector<Boat> enBoats;
};

#endif // MODEL_H
