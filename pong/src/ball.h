#pragma once
#include <ctime>

class Ball
{
private:
    float rect[12];
    time_t lastTick;
public:
    float size; // As a radius (Yaricap)
    float x,y,vx,vy;
    int wasd,ok; // Scores


    Ball(float size);
    ~Ball();
    void update();
    float* getIndecies();
};