//
// Created by Admin on 06.04.2021.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <cstdint>
#include "Snake.h"
#include "Obstacles.h"

//defaults sizes of plane
const uint32_t height = 20;
const uint32_t width = 20;

class Area{
public:
    Area();
    Area(uint32_t _width, uint32_t _height);
    Area(const Area &a);

    uint32_t getWidth() const;

    uint32_t getHeight() const;

private:
    uint32_t width_;
    uint32_t height_;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Game {
public:
    Game();
    Game(const Snake &snake, const Area &area);

    void displaySnakeAndPlane();
    void runGame();

private:
    Area area_;
    Snake snake_;

    void increaseRapid();

    int rapid = 150;
    uint16_t previousPoints = 0;

    bool gameOver = false;
};

#endif //SNAKE_GAME_H
