#include <iostream>
#include <random>
#include <GLFW/glfw3.h>
#include "ball.h"


    // Random Setup . Yoinked from stack overflow.
    std::random_device dev;
    std::mt19937 rnJesus(dev());
    std::uniform_real_distribution<float> randFloat(0.0f,1.0f); // distribution in range [0, 1]

Ball::Ball(float size)
{
    this->size = size;
    this->wasd = 0;
    this->ok = 0;
    this->x = 0;
    this->y = 0;
    this->vx = 5.0f;
    this->vy = 5.0f;
    this->lastTick = glfwGetTime();
}

Ball::~Ball()
{
}


void Ball::update()
{
    double currentTime = glfwGetTime();
    float dt = ((currentTime - this->lastTick) / 25.0f);
    this->lastTick = currentTime;

    if((this->x - (this->size / 2)) < -1)
    {
        this->x = 0;
        this->y = 0;
        std::cout<<wasd<<" - "<<++ok<<"\n";
        this->vx = -5.0f;
        this->vy = randFloat(rnJesus) * this->vx;
    }
    if((this->x + (this->size / 2)) > 1)
    {
        this->x = 0;
        this->y = 0;
        std::cout<<++wasd<<" - "<<ok<<"\n";
        this->vx = 5.0f;
        this->vy = randFloat(rnJesus) * this->vx;

    }
    if(this->y - (this->size / 2) < -1) this->vy *= -1;
    if(this->y + (this->size / 2) > 1) this->vy *= -1;

    this->x += this->vx * dt;
    this->y += this->vy * dt;
}

float* Ball::getIndecies()
{
    
    float ballLeft = (this->x - (this->size / 2));
    float ballRight = (this->x + (this->size / 2));
    float ballDown = (this->y - (this->size / 2));
    float ballUp = (this->y + (this->size / 2));
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