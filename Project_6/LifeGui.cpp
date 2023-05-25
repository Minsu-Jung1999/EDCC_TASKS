#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include "LifeGui.h"
#include "console.h"
#include "gwindow.h"
using namespace std;
using namespace sgl;

LifeGui::LifeGui(LifeModel* modelPointer)
{
    lifeModel = modelPointer;
    aliveColor = "yellow";
    deadColor = "black";
    raws = lifeModel->getRows();
    cols = lifeModel->getCols();
    width = raws * 10;
    height = cols * 10;
    window = new GWindow(width, height);
    window->setWindowTitle("LifeGui");
    window->setLineWidth(1);

    while(true)
    {
        update();
        usleep(5000);  // 대기 시간: 0.5초 (500,000 마이크로초)
    }
}

void LifeGui::drawRect(string color,int& x, int y,int width, int height)
{
    window->setColor(color);
    window->setFillColor(color);
    window->fillRect(x,y,width,height);
    x+=10;
}


void LifeGui::update()
{
    lifeModel->update(); // 모델 업데이트
    int x = 0;
    int y = 0;
    window->clear();
    // GUI 다시 그리기
    for (int row = 0; row < raws; row++) {
        for (int col = 0; col < cols; col++) {
            string color = lifeModel->isAlive(row,col) ? aliveColor : deadColor;
            drawRect(color,x,y,width,height);
            window->repaint();
        }
        y+=10;
        x=0;
    }
}
