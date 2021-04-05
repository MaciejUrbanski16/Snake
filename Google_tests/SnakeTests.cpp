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
    bool col = snake.checkCollsion();
    EXPECT_EQ(col,true);
}