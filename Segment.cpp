//
// Created by Admin on 05.04.2021.
//

#include "Segment.h"
std::ostream& operator <<(std::ostream &out, const Segment &s){
return out << "(" << s.xCoordinate_ << ", " << s.yCoordinate_ << ")" << std::endl;
}

coordinate_t Segment::getXCoordinate() const {
    return xCoordinate_;
}

coordinate_t Segment::getYCoordinate() const {
    return yCoordinate_;
}

void Segment::setXCoordinate(coordinate_t xCoordinate) {
    xCoordinate_ = xCoordinate;
}

void Segment::setYCoordinate(coordinate_t yCoordinate) {
    yCoordinate_ = yCoordinate;
}
