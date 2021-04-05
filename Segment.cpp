//
// Created by Admin on 05.04.2021.
//


#include "Segment.h"

Segment::Segment(const Segment &seg) {
    this->xCoordinate_ = seg.xCoordinate_;
    this->yCoordinate_ = seg.yCoordinate_;
}

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

bool Segment::operator==(const Segment &s) {
    return s.getXCoordinate() == this->getXCoordinate() && s.getYCoordinate() == this->getYCoordinate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Food::Food() {
    srand(time(NULL));
    this->generateSegmentsWithFood();
}

Food::Food(std::vector<Segment> &segmentsWithFood){
    this->segmentsWithFood_ = segmentsWithFood;
}

void Food::generateSegmentsWithFood(){
    srand(time(NULL));
    for(int i=0; i<maxFood; i++){

        this->segmentsWithFood_.push_back(getRandomSegment());
    }

}

bool Food::repeatPositionOfGeneratedFood(Segment &seg) {
    for(int i = 0 ; i < this->segmentsWithFood_.size(); i++){
        if(seg == segmentsWithFood_[i]){
            return true;
        }
    }
    return false;
}

std::vector<Segment> Food::getSegmentsWithFood() {
    return this->segmentsWithFood_;
}

void Food::completeFoodsAfterEating(uint32_t ticks) {
    this->segmentsWithFood_.push_back(getRandomSegment());
}

Segment Food::getRandomSegment() {
    //TODO generate randomly position of food
    Segment tempSegmWithFood;
    //to avoid repeating of food's position
    do {
        Segment s(23 - rand() % 22, 13 - rand() % 12);
        tempSegmWithFood = s;
    }while(repeatPositionOfGeneratedFood(tempSegmWithFood));

    return tempSegmWithFood;
}





