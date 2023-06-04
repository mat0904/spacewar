#include "../../include/prototype.hpp"

int event(Game *game)
{
    sf::Event event;
    while (game->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game->window->close();
        }
    }
    return 0;
}
