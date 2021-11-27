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

    playerMoveAmount = sf::Vector2f(0, 0);

    return exit;
}
