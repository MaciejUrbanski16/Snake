//
// Created by Admin on 05.04.2021.
//

#include "Snake.h"

Snake::Snake() {

    this->snakeSegments_.emplace_back(6,10);
    this->snakeSegments_.emplace_back(7,10);
    this->snakeSegments_.emplace_back(8,10);
    this->snakeSegments_.emplace_back(9,10);
    this->snakeSegments_.emplace_back(10,10);

    this->food_ = Food();
}

Snake::Snake(std::vector<Segment> &snakeSegments) {
    this->snakeSegments_ = snakeSegments;

    this->food_ = Food();
}

void Snake::riseUp(){
    for(int i = 0 ; i < this->food_.getSegmentsWithFood().size(); i++) {
        if (snakeSegments_[0] == this->food_.getSegmentsWithFood()[i]){

            // snake is getting longer
            snakeSegments_.insert(snakeSegments_.begin(),this->food_.getSegmentsWithFood()[i]);

            //food is removed after eating it
            std::vector<Segment> tempSegments = this->food_.getSegmentsWithFood();
            tempSegments.erase(tempSegments.begin() + i);
            this->food_.setSegmentsWithFood(tempSegments);
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

bool Snake::checkCollsion() {
    bool collision = false;

    for(int i = 1; i < this->snakeSegments_.size();i++){

        if(this->snakeSegments_[i] == this->snakeSegments_[0]){
            collision = true;
            break;
        }
    }

    return collision;
}
