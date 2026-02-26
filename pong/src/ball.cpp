#include <iostream>
#include <ctime>
#include "ball.h"



Ball::Ball(float size)
{
    this->size = size;
    this->wasd = 0;
    this->ok = 0;
    this->vx = 0.3;
    this->vy = 0.3;
}

Ball::~Ball()
{
}


void Ball::update()
{
    time_t currentTime = time(NULL);
    float dt = (1.0f / (currentTime - this->lastTick));
    this->lastTick = currentTime;

    if((this->x - (this->size / 2)) < 0)
    {
        this->x = 0;
        std::cout<<wasd<<" - "<<++ok<<"\n";
        this->vx = -1.0f;
    }
    if((this->x + (this->size / 2)) > 1)
    {
        this->x = 0;
        std::cout<<++wasd<<" - "<<ok<<"\n";
        this->vx = 11.0f;

    }
    if(this->y - (this->size / 2) < 0) this->vy *= -1;
    if(this->y + (this->size / 2) > 1) this->vy *= -1;

    this->x += this->vx * dt;
    this->y += this->vy * dt;
}

float* Ball::getIndecies()
{
    
    float ballLeft = (this->x - (this->size / 2));
    float ballRight = (this->x + (this->size / 2));
    float ballDown = (this->y - (this->size / 2));
    float ballUp = this->y + (this->size / 2);
    rect[0] = ballLeft;
    rect[1] = ballDown;
    rect[2] = 0;
    rect[3] = ballLeft;
    rect[4] = ballUp;
    rect[5] = 0;
    rect[6] = ballRight;
    rect[7] = ballDown;
    rect[8] = 0;
    rect[9] = ballRight;
    rect[10] =ballUp;
    rect[11] = 0;
    return this->rect;
}