#include "../Base.hpp"

void Base::checkMoves() {
    if (totalTime >= 0.1f) {
        if (playerMoveDirection == 0) {
            playerMoveAmount = sf::Vector2f(0, -player.getShape().getSize().x);
        } else if (playerMoveDirection == 1) {
            playerMoveAmount = sf::Vector2f(player.getShape().getSize().y, 0);
        } else if (playerMoveDirection == 2) {
            playerMoveAmount = sf::Vector2f(0, player.getShape().getSize().x);
        } else if (playerMoveDirection == 3) {
            playerMoveAmount = sf::Vector2f(-player.getShape().getSize().y, 0);
        }

        totalTime = 0;
        snakePathChosen = 0;
    }

    if (player.getShape().getGlobalBounds().intersects(collides[0].getShape().getGlobalBounds())) {
        collides.push_back(BasicShape(player.getShape().getSize(), player.getShape().getPosition(), sf::Color::White, 1));
        collides[0].getShape().setPosition(sf::Vector2f(ut.getRandomInt(0, int(snakePath[0].size() - 1) * 32), ut.getRandomInt(0, (snakePath.size() - 1) * 32)));
        snakeSize += 1;
    }

    for (int i = 1; i < collides.size(); i++) {
        if(player.getShape().getGlobalBounds().intersects(collides[i].getShape().getGlobalBounds())) {
            exit(0);
        }
    }

    if (collides.size() - 1 > snakeSize) {
        collides.pop_back();
    }

    player.getShape().move(playerMoveAmount);
}
