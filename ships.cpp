#include "ships.h"

BattleShip::BattleShip()
{
    this->partsQuant = 4;
}

BattleShip::BattleShip(int ind1, int ind2, int ind3, int ind4)
{
    this->parts.insert(ind1, INTACT);
    this->parts.insert(ind2, INTACT);
    this->parts.insert(ind3, INTACT);
    this->parts.insert(ind4, INTACT);
}

BattleShip::~BattleShip()
{
}

////////////////////////////////////////////////////////////////////////////////////

Cruiser::Cruiser()
{
    this->partsQuant = 3;
}

Cruiser::Cruiser(int ind1, int ind2, int ind3)
{
    this->parts.insert(ind1, INTACT);
    this->parts.insert(ind2, INTACT);
    this->parts.insert(ind3, INTACT);
}

Cruiser::~Cruiser()
{
}

////////////////////////////////////////////////////////////////////////////////////

Destroyer::Destroyer()
{
    this->partsQuant = 2;
}

Destroyer::Destroyer(int ind1, int ind2)
{
    this->parts.insert(ind1, INTACT);
    this->parts.insert(ind2, INTACT);
}

Destroyer::~Destroyer()
{
}

////////////////////////////////////////////////////////////////////////////////////

Boat::Boat()
{
    this->partsQuant = 1;
}

Boat::Boat(int ind1)
{
    this->parts.insert(ind1, INTACT);
}

Boat::~Boat()
{
}
