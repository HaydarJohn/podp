#include"Game.h"

Game::Game()
{
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight = 720;
    _gameState = GameState::PLAY;
}

Game::~Game()
{

}

void Game::run()
{
    initSystem();
}

void Game::initSystem()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow("Pass Out Day Project\0",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight,SDL_WINDOW_OPENGL);
}

void Game::processInput()
{

}
void Game::gameloop()
{
    while (_gameState != GameState::Exit)
    {
        processInput();
    }
    
}
