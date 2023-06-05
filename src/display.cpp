#include "../include/prototype.hpp"

int display(Game *game)
{
    game->player->view.setCenter(game->player->ship.body.getPosition());
    game->window->setView(game->player->view);
    game->player->set_rotation();
    game->player->booster_break();
    float speed = sqrt(pow(game->player->ship.move_vector.x, 2) + pow(game->player->ship.move_vector.y, 2));
    game->player->hud.update(game->player->ship.angle, speed, &game->player->view);
    game->player->hud.display(game->window);
    game->player->calcul_move_vector();
    game->player->display(game->window);
    return 0;
}
