#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->view.setCenter(game->player->ship.body.getPosition());
    game->window->setView(game->player->view);
    game->window->draw(game->star);
    game->player->set_rotation();
    game->player->booster_break();
    game->player->hud.update(game->player->ship.angle, game->player->ship.move_vector.x);
    game->player->hud.display(game->window);
    game->player->calcul_move_vector();
    game->player->display(game->window);
    return 0;
}
