//
// Created by Admin on 05.04.2021.
//


#include <set>
#include "Segment.h"
#include "Game.h"

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

ElementsOnPlane::ElementsOnPlane() {
    srand(time(NULL));

    this->generateSegmentsWithObstacles();
    this->generateSegmentsWithFood();
}

ElementsOnPlane::ElementsOnPlane(std::vector<Segment> &segmentsWithFood){
    this->segmentsWithFood_ = segmentsWithFood;
}

void ElementsOnPlane::generateSegmentsWithFood(){

    for(int i=0; i<maxFood; i++){

        this->segmentsWithFood_.push_back(getRandomSegment());
    }

}

void ElementsOnPlane::generateSegmentsWithObstacles() {

    uint32_t totalArea = height * width;
    uint32_t numberOfObstacles = 2 *((totalArea - (totalArea%100))/100);

    //TODO generating groups of obstacles
    std::vector<std::set<Segment>> groupsOfObstacles;

    for(int i = 0 ; i  < numberOfObstacles; i++){

        Segment temp = getRandomSegment();
        this->segmentsWithObstacles_.push_back(temp);

        generateGroupOfObstacles(i);


    }
}

void ElementsOnPlane::generateGroupOfObstacles(int i) {
    for(int j = 0 ; j< i ; j++){

        int situateObstacle = rand()%4;
        Segment tempSegm;

        //generate obstacle next to previous obstacle
        switch(situateObstacle){
            case 0:
                tempSegm.setXCoordinate(this->segmentsWithObstacles_.back().getXCoordinate());
                tempSegm.setYCoordinate(this->segmentsWithObstacles_.back().getYCoordinate() + 1);
                this->segmentsWithObstacles_.push_back(tempSegm);

                break;
            case 1:
                tempSegm.setXCoordinate(this->segmentsWithObstacles_.back().getXCoordinate());
                tempSegm.setYCoordinate(this->segmentsWithObstacles_.back().getYCoordinate() - 1);
                this->segmentsWithObstacles_.push_back(tempSegm);

                break;
            case 2:
                tempSegm.setXCoordinate(this->segmentsWithObstacles_.back().getXCoordinate() + 1);
                tempSegm.setYCoordinate(this->segmentsWithObstacles_.back().getYCoordinate());
                this->segmentsWithObstacles_.push_back(tempSegm);

                break;
            case 3:
                tempSegm.setXCoordinate(this->segmentsWithObstacles_.back().getXCoordinate() - 1);
                tempSegm.setYCoordinate(this->segmentsWithObstacles_.back().getYCoordinate());
                this->segmentsWithObstacles_.push_back(tempSegm);
                break;
            default:
                break;
        }
    }
}

bool ElementsOnPlane::repeatPositionOfGeneratedFoodOrObstacle(Segment &seg) {
    for(int i = 0 ; i < this->segmentsWithFood_.size(); i++){
        if(seg == segmentsWithFood_[i]){
            return true;
        }
    }

    for(auto & segmentsWithObstacle : this->segmentsWithObstacles_){
        if(seg == segmentsWithObstacle){
            return true;
        }
    }
    return false;
}

std::vector<Segment> ElementsOnPlane::getSegmentsWithFood() {
    return this->segmentsWithFood_;
}

std::vector<Segment> ElementsOnPlane::getSegmentsWithObstacles() {
    return this->segmentsWithObstacles_;
}

void ElementsOnPlane::completeFoodsAfterEating(uint32_t ticks) {
    this->segmentsWithFood_.push_back(getRandomSegment());
}

Segment ElementsOnPlane::getRandomSegment() {

    Segment tempSegmWithFood;
    //to avoid repeating of food's position
    do {
        Segment s(width - 2 - rand() % (width - 3), height -2  - rand() % (height - 3));
        tempSegmWithFood = s;
    }while(repeatPositionOfGeneratedFoodOrObstacle(tempSegmWithFood));

    return tempSegmWithFood;
}

void ElementsOnPlane::setSegmentsWithFood(std::vector<Segment> &newSegments) {
    this->segmentsWithFood_ = newSegments;
}









