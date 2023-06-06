#include "../../include/prototype.hpp"

static int player_event_pressed(Game *game, sf::Event *event)
{
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::D) {
            game->player->d_button = true;
        }
        if (event->key.code == sf::Keyboard::Q) {
            game->player->q_button = true;
        }
        if (event->key.code == sf::Keyboard::Z) {
            game->player->z_button = true;
        }
        if (event->key.code == sf::Keyboard::S) {
            game->player->s_button = true;
        }
        if (event->key.code == sf::Keyboard::Space) {
            game->player->space_button = true;
        }
    }
    return 0;
}

static int player_event_released(Game *game, sf::Event *event)
{
    if (event->type == sf::Event::KeyReleased) {
        if (event->key.code == sf::Keyboard::D)
            game->player->d_button = false;
        if (event->key.code == sf::Keyboard::Q)
            game->player->q_button = false;
        if (event->key.code == sf::Keyboard::Z)
            game->player->z_button = false;
        if (event->key.code == sf::Keyboard::S)
            game->player->s_button = false;
        if (event->key.code == sf::Keyboard::Space)
            game->player->space_button = false;
        if (event->key.code == sf::Keyboard::Right)
            game->player->ship.angle = 0;
        if (event->key.code == sf::Keyboard::Left)
            game->player->ship.angle = 180;
        if (event->key.code == sf::Keyboard::Down)
            game->player->ship.angle = 90;
        if (event->key.code == sf::Keyboard::Up)
            game->player->ship.angle = 270;
    }
    return 0;
}

int player_event(Game *game, sf::Event *event)
{
    player_event_released(game, event);
    player_event_pressed(game, event);
    return 0;
}
