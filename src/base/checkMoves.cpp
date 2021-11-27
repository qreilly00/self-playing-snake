#include "../Base.hpp"

void Base::checkMoves() {
    if (totalTime >= 1) {
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
    }

    player.getShape().move(playerMoveAmount);
}
