//
// Created by Admin on 05.04.2021.
//

#ifndef SNAKE_SEGMENT_H
#define SNAKE_SEGMENT_H

#include <stdint.h>
#include <ctime>
#include <ostream>
#include <vector>

typedef uint32_t coordinate_t ;
class Segment{
public:
    Segment(){}

    Segment(coordinate_t xCoordinate, coordinate_t yCoordinate): xCoordinate_(xCoordinate), yCoordinate_(yCoordinate){}

    Segment(const Segment &seg);

    friend std::ostream& operator <<(std::ostream &out, const Segment &s);

    bool operator == (const Segment &seg);

    coordinate_t getXCoordinate() const;

    coordinate_t getYCoordinate() const;

    void setXCoordinate(coordinate_t xCoordinate);

    void setYCoordinate(coordinate_t yCoordinate);

private:
    coordinate_t xCoordinate_, yCoordinate_;
};//Segment

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ElementsOnPlane{
public:
    ElementsOnPlane();

    ElementsOnPlane(std::vector<Segment> &segmentsWithFood);

    std::vector<Segment> getSegmentsWithFood();
    std::vector<Segment> getSegmentsWithObstacles();

    void generateSegmentsWithFood();
    void generateSegmentsWithObstacles();

    void completeFoodsAfterEating(uint32_t ticks);

    Segment getRandomSegment();

    void setSegmentsWithFood(std::vector<Segment> &newFood);
    void setSegmentsObstacles(const std::vector<Segment> &newObst);

private:
    std::vector<Segment> segmentsWithFood_;

    std::vector<Segment> segmentsWithObstacles_;



    bool repeatPositionOfGeneratedFoodOrObstacle(Segment &seg);

    uint16_t maxFood = 5;

    void generateGroupOfObstacles(int i);
};


#endif //SNAKE_SEGMENT_H
