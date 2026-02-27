#include "paddle.h"
#include "ball.h"


Paddle::Paddle(bool side,float width,float height)
{
    this->side =side;
    this->width = width;
    this->height = height;
    this->x = -0.7; // Left Paddle
    if(side == 1) this->x *= -1;    // Right Paddle
}

Paddle::~Paddle()
{
}

// This code is bad. My life :S
bool Paddle::checkCollide(Ball* ball)
{
    // For Horizontal check
    float paddleLeft = this->x - (this->width / 2);
    float paddleRight = this->x + (this->width / 2);
    float ballLeft = ball->x - (ball->size /2);
    float ballRight = ball->x + (ball->size /2);
    // For Vertical check
    float paddleDown = this->y - (this->height / 2);
    float paddleUp = this->y + (this->height / 2);
    float ballDown = ball->y - (ball->size /2);
    float ballUp = ball->y + (ball->size /2);


    bool ballSide = 0;
    if(ball->vx > 0) ballSide = 1;
    if(this->side == ballSide)  // IDK why i did this optimization.
    {
        // Check Horizontal collision
        if(paddleLeft < ballRight && paddleRight > ballLeft)
        {
            // Check Vertical collision
            if(paddleDown < ballUp && paddleUp > ballDown)
            {
                return true;
            }
        }
    }

    return false;
}

float* Paddle::getIndecies()
{
    
    float paddleLeft = (this->x - (this->width / 2));
    float paddleRight = (this->x + (this->width / 2));
    float paddleDown = (this->y - (this->height / 2));
    float paddleUp = this->y + (this->height / 2);
    rect[0] = paddleLeft;
    rect[1] = paddleDown;
    rect[2] = 0;
    rect[3] = paddleLeft;
    rect[4] = paddleUp;
    rect[5] = 0;
    rect[6] = paddleRight;
    rect[7] = paddleDown;
    rect[8] = 0;
    rect[9] = paddleRight;
    rect[10] = paddleUp;
    rect[11] = 0;
    return this->rect;
}