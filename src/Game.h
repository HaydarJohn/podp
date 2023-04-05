#ifndef _GAME_H
#define _GAME_H

#include<SDL2/SDL.h>

enum class GameState {PLAY , Exit };

class Game
{
    public:
    Game();
    ~Game();

    void run();


    private:
    void initSystem();
    void processInput();
    void gameloop();


    SDL_Window* _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;



};


#endif