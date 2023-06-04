#include "../include/prototype.hpp"

int spacewar(const int ac, const char **av)
{
    Game *game = new Game();
    gloop(game);
    delete game->player;
    delete game->window;
    delete game;
    return 0;
}
