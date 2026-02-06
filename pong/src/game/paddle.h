#pragma once
#include <stdint.h>

enum PaddleSide
{
    Left,
    Right,
    Up,
    Down
};

class Paddle
{
private:
    // 0 is lower and 255 is upper limit.
    uint8_t verticalPosition;
public:
    Paddle(PaddleSide side);
    ~Paddle();

    // Only accepts Up or Down
    void movePaddle(PaddleSide side);
};