#pragma once
#include<easyx.h>
#include "player/Player.h"

class Dice
{
private:
    int num_ = 1;
    int x_ = 350;
    int y_ = 170;
    int width_ = 100;
    int height_ = 100;
    IMAGE img_[6];
public:
    Dice();
    ~Dice();

    void Draw();                            // ��ʾ����
    bool inArea(const ExMessage& msg);
    int Random();                            // ��ȡ�������//return 1-6

};