#pragma once

class Ball;

class Paddle
{
private:
    float width,height,x,y;
    bool side;  // If true then ball is located in the right.
    float rect[12];
public:
    Paddle(bool side,float width,float height);
    ~Paddle();
    bool checkCollide(Ball* ball);
    float* getIndecies();
};