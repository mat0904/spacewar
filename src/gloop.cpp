#include "../include/prototype.hpp"

int gloop(Game *game)
{
    while (game->window->isOpen()) {
        game->window->clear(sf::Color::Black);
        event(game);
        display(game);
        game->window->display();
    }
    return 0;
}
