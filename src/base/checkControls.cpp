#include "../Base.hpp"

bool Base::checkControls() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            return 1;
        }

        /*if (event.type == sf::Event::TextEntered) {
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
        }*/
    }

    if (snakePathChosen == 0) {
        char tmp = snakePath[snakePathPos.y][snakePathPos.x];
        if(tmp != '#') playerMoveDirection = tmp - 48;
        std::cout << snakePath[snakePathPos.y][snakePathPos.x] << std::endl;

        if(playerMoveDirection == 0) {
            snakePathPos.y -= 1;
        } else if(playerMoveDirection == 1) {
            snakePathPos.x += 1;
        } else if(playerMoveDirection == 2) {
            snakePathPos.y += 1;
        } else if(playerMoveDirection == 3) {
            snakePathPos.x -= 1;
        }

        snakePathChosen = 1;
    }

    /*if (moveChosen == 0) {
        std::cout << snakePath[snakePathPos.x][snakePathPos.y] << std::endl;
    }*/

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
