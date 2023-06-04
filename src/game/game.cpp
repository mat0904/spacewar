#include "../../include/prototype.hpp"
#include <SFML/Window/WindowStyle.hpp>

Game::Game()
{
    sf::VideoMode videomode = {1920, 1080, 32};
    window = new sf::RenderWindow(videomode, "spacewar", sf::Style::Fullscreen);
    window->setFramerateLimit(240);
    player = new Player();
}
