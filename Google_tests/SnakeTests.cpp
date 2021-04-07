//
// Created by Admin on 05.04.2021.
//

#include "../Snake.h"

#include <gtest/gtest.h>

TEST(Snake,checkCollision){
    //GIVEN
    std::vector<Segment> s{Segment(1,2),Segment(1,3),
                           Segment(2,3),Segment(2,2),Segment(1,2)};
    Snake snake(s);

    //WHEN
    bool col = snake.checkCollision();
    EXPECT_EQ(col,true);
}

TEST(Snake,checkCollisionWithObstacle){
    //GIVEN
    std::vector<Segment> s{Segment(1,2),Segment(1,3),
                           Segment(1,4),Segment(1,5),Segment(1,6)};
    Snake snake;

    //ElementsOnPlane elements;
    coordinate_t X = snake.getSegments()[0].getXCoordinate();
    coordinate_t Y = snake.getSegments()[0].getYCoordinate();
    std::vector<Segment> obst = snake.getElements().getSegmentsWithObstacles();

    obst[0].setXCoordinate(X);
    obst[0].setYCoordinate(Y);
    snake.getElements().setSegmentsObstacles(obst);

    //WHEN
    bool col = snake.checkCollision();
    EXPECT_EQ(col,true);
}