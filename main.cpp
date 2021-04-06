#include <iostream>

#include "Segment.h"
#include "Snake.h"
#include "Game.h"

int main() {

    Area area;
    Snake snake;


    Game game(snake,area);
    game.runGame();
    return 0;
}
