#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->set_rotation();
    game->player->Display(game->window);
    return 0;
}
