#include "../Base.hpp"

void Base::checkMoves() {
    if (totalTime >= 0.01) {
        snakeBody.push_back(BasicShape(player.getShape().getSize(), player.getShape().getPosition(), sf::Color::Blue, 1));

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
        collides[0].getShape().setPosition(sf::Vector2f(ut.getRandomInt(0, int(snakePath[0].size() - 2) * 32), ut.getRandomInt(0, (snakePath.size() - 2) * 32)));
        snakeSize += 1;
    }

    for (int i = 1; i < snakeBody.size(); i++) {
        if(player.getShape().getGlobalBounds().intersects(snakeBody[i].getShape().getGlobalBounds())) {
            //exit(0);
        }
    }

    if (snakeBody.size() > snakeSize) {
        snakeBody.erase(snakeBody.begin());
    }

    player.getShape().move(playerMoveAmount);
}
