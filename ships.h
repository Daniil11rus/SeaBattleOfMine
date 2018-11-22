#ifndef SHIPS_H
#define SHIPS_H

#include "used_libraries.h"

enum shipPartState
{
    INTACT,
    DAMAGED
};

class Ship
{
public:
    virtual ~Ship() {}
    QMap<int, shipPartState> parts;
    int partsQuant;
};

class BattleShip : public Ship
{
public:
    BattleShip();
    BattleShip(int ind1, int ind2, int ind3, int ind4);
    ~BattleShip();
};

class Cruiser : public Ship
{
public:
    Cruiser();
    Cruiser(int ind1, int ind2, int ind3);
    ~Cruiser();
};

class Destroyer : public Ship
{
public:
    Destroyer();
    Destroyer(int ind1, int ind2);
    ~Destroyer();
};

class Boat : public Ship
{
public:
    Boat();
    Boat(int ind1);
    ~Boat();
};

#endif // SHIPS_H
