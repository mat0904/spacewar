#include "../../include/prototype.hpp"

int player_event(Game *game, sf::Event *event)
{
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::D) {
            game->player->rotation += 5;
        }
        if (event->key.code == sf::Keyboard::Q) {
            game->player->rotation -= 5;
        }
        if (event->key.code == sf::Keyboard::Z) {
            game->player->is_boosting = true;
        }
    }
    if (event->type == sf::Event::KeyReleased) {
        if (event->key.code == sf::Keyboard::Z) {
            game->player->is_boosting = false;
        }
    }
    return 0;
}
