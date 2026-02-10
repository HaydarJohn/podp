#include "paddle.h"

Paddle::Paddle(PaddleSide side)
{
    this->verticalPosition = 127;
}

Paddle::~Paddle()
{

}

void Paddle::movePaddle(PaddleSide side)
{
    if(side == PaddleSide::Down)
    {
        this->verticalPosition -= 5;
        if(this->verticalPosition < 0)
        {
            this->verticalPosition = 0;
        }
    }
    else if(side == PaddleSide::Up)
    {
        this->verticalPosition += 5;
        if(this->verticalPosition > 255)
        {
            this->verticalPosition = 255;
        }
    }
}