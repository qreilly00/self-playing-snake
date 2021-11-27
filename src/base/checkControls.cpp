#include "../Base.hpp"

bool Base::checkControls() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            return 1;
        }

        if (event.type == sf::Event::TextEntered) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                if (playerMoveDirection == 0) {
                    playerMoveDirection = 3;
                } else playerMoveDirection --;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (playerMoveDirection == 3) {
                    playerMoveDirection = 0;
                } else playerMoveDirection ++;
            }
        }
    }

    // Controls.
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (playerMoveDirection == 0) {
            playerMoveDirection = 3;
        } else playerMoveDirection --;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (playerMoveDirection == 3) {
            playerMoveDirection = 0;
        } else playerMoveDirection ++;
    }*/

    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}

    return 0;
}
