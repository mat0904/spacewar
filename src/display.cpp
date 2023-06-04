#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->body.setRotation(game->player->rotation);
    game->player->booster.setRotation(game->player->rotation);
    game->player->Display(game->window);
    return 0;
}
