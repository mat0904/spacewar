#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->set_rotation();
    game->player->calcul_move_vector();
    game->player->detect_border();
    game->player->display(game->window);
    return 0;
}
