#include "../Base.hpp"

bool Base::gameLoop() {
    ut.setTime();
    totalTime += ut.getTime();

    //std::cout << totalTime << std::endl;

    bool exit = 0;

    //ut.getFileLines("../map-rooms-1");

    exit =
    checkControls();
    checkMoves();
    drawWindow();

    if (snakeSize >= 100) {
        exit = 1;
    }

    //collides[0].getShape().setPosition(sf::Vector2f(ut.getRandomInt(0, int(snakePath[0].size() - 1) * 32), ut.getRandomInt(0, (snakePath.size() - 1) * 32)));

    playerMoveAmount = sf::Vector2f(0, 0);

    return exit;
}
