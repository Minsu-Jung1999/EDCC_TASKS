
#ifndef LIFEGUI_H
#define LIFEGUI_H

#include <iostream>
#include <string>

#include "LifeModel.h"
#include "gwindow.h"
using namespace sgl;
class LifeGui {
private:
    LifeModel* lifeModel;
    std::string aliveColor;
    std::string deadColor;
    GWindow* window;
    int width;
    int height;
    int raws;
    int cols;
    void drawRect(std::string color,int& x, int y,int width, int height);
public:
    LifeGui(LifeModel* modelPointer);
    void update();
};
#endif // LIFEGUI_H
