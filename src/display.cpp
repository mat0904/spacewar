#include "../include/prototype.hpp"

int display(Game *game)
{
    game->draw_background();
    game->player->view.setCenter(game->player->ship.body.getPosition());
    game->window->setView(game->player->view);
    game->player->set_rotation();
    game->player->booster_break();
    game->player->hud.update(&game->player->ship, &game->player->view);
    game->player->hud.display(game->window);
    game->player->calcul_move_vector();
    game->player->display(game->window);
    return 0;
}
