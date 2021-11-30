#include "../Base.hpp"
Base::Base() {
    //tu.setTime();
    totalTime = 0;

    //playerBorders.resize(4);

    //currentLevel = 1;

    playerMoveDirection = 1;

    snakeSize = 3;
    snakePath = ut.getFileLines("../hamiltonian-circuit");
    snakePathPos = sf::Vector2f(1, 0);
    snakePathChosen = 0;

    createWindow();
    createPlayer();

    collides.push_back(BasicShape(sf::Vector2f(32, 32), sf::Vector2f(0, 0), sf::Color::White, 1));
    //designLevel(currentLevel);

    //window.setFramerateLimit(1);
    //view.setSize(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    // Example.
    //collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(512, 512), 0, 1, sf::Color::White));
}
