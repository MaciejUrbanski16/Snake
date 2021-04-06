//
// Created by Admin on 05.04.2021.
//

#include "Snake.h"

Snake::Snake() {

    //default position of snake after start
    this->snakeSegments_.emplace_back(10,10);
    this->snakeSegments_.emplace_back(9,10);
    this->snakeSegments_.emplace_back(8,10);
    this->snakeSegments_.emplace_back(7,10);
    this->snakeSegments_.emplace_back(6,10);

    this->elementsOnPlane_ = ElementsOnPlane();
}

Snake::Snake(std::vector<Segment> &snakeSegments) {
    this->snakeSegments_ = snakeSegments;

    this->elementsOnPlane_ = ElementsOnPlane();
}

void Snake::riseUp(){
    for(int i = 0 ; i < this->elementsOnPlane_.getSegmentsWithFood().size(); i++) {
        if (snakeSegments_[0] == this->elementsOnPlane_.getSegmentsWithFood()[i]){

            // snake is getting longer
            snakeSegments_.insert(snakeSegments_.begin(),this->elementsOnPlane_.getSegmentsWithFood()[i]);

            //food is removed after eating it
            std::vector<Segment> tempSegments = this->elementsOnPlane_.getSegmentsWithFood();
            tempSegments.erase(tempSegments.begin() + i);

            this->elementsOnPlane_.setSegmentsWithFood(tempSegments);
        }
    }
}

void Snake::setNewPositionsAfterMovement(Direction dir){

    switch(dir){
        case Direction::UP:
            this->snakeSegments_.insert(this->snakeSegments_.begin(),Segment(this->snakeSegments_[0].getXCoordinate(),this->snakeSegments_[0].getYCoordinate()  - 1));
            this->snakeSegments_.pop_back();
            break;
        case Direction::DOWN:
            this->snakeSegments_.insert(this->snakeSegments_.begin(),Segment(this->snakeSegments_[0].getXCoordinate(),this->snakeSegments_[0].getYCoordinate()  + 1));
            this->snakeSegments_.pop_back();
            break;
        case Direction::LEFT:
            this->snakeSegments_.insert(this->snakeSegments_.begin(),Segment(this->snakeSegments_[0].getXCoordinate() - 1,this->snakeSegments_[0].getYCoordinate()));
            this->snakeSegments_.pop_back();
            break;
        case Direction::RIGHT:
            this->snakeSegments_.insert(this->snakeSegments_.begin(),Segment(this->snakeSegments_[0].getXCoordinate() + 1,this->snakeSegments_[0].getYCoordinate()));
            this->snakeSegments_.pop_back();
            break;
        default:
            break;
    }

}

bool Snake::checkCollision() {
    bool collision = false;

    for(int i = 3; i < this->snakeSegments_.size();i++){

        if(this->snakeSegments_[i] == this->snakeSegments_[0]){
            collision = true;
            break;
        }
    }

    return collision;
}

std::vector<Segment> Snake::getSegments() {
    return this->snakeSegments_;
}

ElementsOnPlane Snake::getElements() {
    return this->elementsOnPlane_;
}
