#ifndef MODEL_H
#define MODEL_H

#include "field.h"

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
    ~Model() {}
    State getState();
    void setState(State state);
    QString getMyField();
    QString getEnField();
    void setCellInMyField(int ind, Cell cell);
    Cell getCellInMyField(int ind);

private:
    Field *myField;
    Field *enField;
    State state;
};

#endif // MODEL_H
