#include "controller.h"
#include "defines.h"
#include "mainwindow.h"

Controller::Controller(Model *model)
{
    this->model = model;
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
        }

        w->update();
    }
}
