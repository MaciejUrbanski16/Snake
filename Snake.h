//
// Created by Admin on 05.04.2021.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <vector>
#include "Segment.h"

class Snake {
public:
    Snake();
    Snake(std::vector<Segment> &snakeSegments);


    //direction of snake's movement
    enum class Direction{
        UP, DOWN, LEFT, RIGHT
    };

    void riseUp();
    void setNewPositionsAfterMovement(Direction dir);

    bool checkCollsion();


private:
    std::vector<Segment> snakeSegments_;
    Food food_;
};


#endif //SNAKE_SNAKE_H
