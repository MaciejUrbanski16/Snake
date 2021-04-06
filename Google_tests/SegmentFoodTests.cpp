//
// Created by Admin on 01.04.2021.
//
#include <gtest/gtest.h>
#include "../Segment.h"


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Segment, CheckCreatingOfSegment){
    //GIVEN
    Segment s(12,3);

    //WHEN
    coordinate_t x = 15;
    s.setXCoordinate(15);

    //THEN
    EXPECT_EQ(s.getXCoordinate(),x);
}

TEST(Food,GeneretingFood){
    //GIVEN
    ElementsOnPlane f; // constructor generates segments with food

    //WHEN

    //THEN
    EXPECT_EQ(5,f.getSegmentsWithFood().size());
}