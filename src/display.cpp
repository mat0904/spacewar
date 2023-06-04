#include "../include/prototype.hpp"

int display(Game *game)
{
    printf("Rotation: %f\n", game->player->rotation);
    game->player->set_rotation();
    game->player->set_speed();
    game->player->calcul_move_vector();
    game->player->detect_border();
    game->player->display(game->window);
    return 0;
}
