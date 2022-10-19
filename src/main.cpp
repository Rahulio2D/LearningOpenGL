#include "Headers/Game.h"

int main()
{
    Game* game = new Game("Learning OpenGL", 1280, 720);
    game->Initialise();

    while(game->IsRunning())
    {
        game->Update();
        game->Render();
        game->HandleEvents();
    }

    delete game;
}