#pragma once

class Ball;

class Paddle
{
private:
bool side;  // If true then ball is located in the right.
float rect[12];
public:
    float width,height,x,y;
    Paddle(bool side,float width,float height);
    ~Paddle();
    bool checkCollide(Ball* ball);
    float* getIndecies();
};