#pragma once

class Ball
{
private:
    float rect[12];
    double lastTick;
public:
    float size; // As a radius (Yaricap)
    float x,y,vx,vy;
    int wasd,ok; // Scores


    Ball(float size);
    ~Ball();
    void update();
    float* getIndecies();
};