#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->set_rotation();
    game->player->set_speed();
    game->player->display(game->window);
    return 0;
}
