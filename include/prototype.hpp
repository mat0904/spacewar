#ifndef PROTOTYPE_HPP_
    #define PROTOTYPE_HPP_

    #include "include.hpp"
    #include "game.hpp"

    int spacewar(const int ac, const char **av);
    int gloop(Game *game);
    int display(Game *game);

    int event(Game *game);
    int player_event(Game *game, sf::Event *event);

#endif //PROTOTYPE_HPP_
