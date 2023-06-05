#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->view.setCenter(game->player->ship.body.getPosition());
    game->window->setView(game->player->view);
    game->window->draw(game->star);
    game->player->set_rotation();
    game->player->booster_break();
    game->player->calcul_move_vector();
    game->player->display(game->window);
    return 0;
}
