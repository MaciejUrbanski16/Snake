//
// Created by Admin on 05.04.2021.
//

#ifndef SNAKE_SEGMENT_H
#define SNAKE_SEGMENT_H

#include <stdint.h>
#include <ostream>

typedef uint32_t coordinate_t ;
class Segment{
public:
    Segment(coordinate_t xCoordinate, coordinate_t yCoordinate): xCoordinate_(xCoordinate), yCoordinate_(yCoordinate){
    }
    friend std::ostream& operator <<(std::ostream &out, const Segment &s);

    coordinate_t getXCoordinate() const;

    coordinate_t getYCoordinate() const;

    void setXCoordinate(coordinate_t xCoordinate);

    void setYCoordinate(coordinate_t yCoordinate);

private:
    coordinate_t xCoordinate_, yCoordinate_;
};


#endif //SNAKE_SEGMENT_H
