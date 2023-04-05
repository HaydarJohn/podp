#include"Game.h"
#include<SDL2/SDL.h>
#include<GL/glew.h>

#include<iostream>

int main(int argc,const char** argv)
{
    Game game;

    game.run();

    std::cin.get();

    return 0;    
}