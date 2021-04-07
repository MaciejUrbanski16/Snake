//
// Created by Admin on 06.04.2021.
//

#include <iostream>
#include <chrono>
#include <conio.h>
#include "Thread_for_MINGW/mingw.thread.h"
#include "Game.h"

Area::Area() {
    this->width_ = width;
    this->height_ = height;
}

Area::Area(uint32_t _width, uint32_t _height) {
    this->width_ = _width;
    this->height_ = _height;
}

uint32_t Area::getWidth() const {
    return width_;
}

uint32_t Area::getHeight() const {
    return height_;
}

Area::Area(const Area &a) {
    this->height_ = a.getHeight();
    this->width_ = a.getWidth();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Game::Game(const Snake &snake, const Area &area) {
    this->snake_ = snake;
    this->area_ = area;

    //set default direction
    snake_.setNewPositionsAfterMovement(Snake::Direction::RIGHT);
}

void Game::displaySnakeAndPlane() {
    system("cls");
    for(int i=0; i<area_.getHeight(); i++){
        for(int j=0; j< area_.getWidth(); j++){
            if(i == 0 || i == area_.getHeight() - 1 || j==0 || j == area_.getWidth() - 1){
                std::cout<<'#';
            }
            else{
                bool isSnakeHere = false;
                bool isFoodHere = false;
                bool isObstacleHere = false;
                for(int k = 0; k<snake_.getSegments().size(); k++){
                    if(snake_.getSegments()[k].getXCoordinate() == j && snake_.getSegments()[k].getYCoordinate() == i){
                        isSnakeHere = true;
                        break;
                    }
                }
                for(int k = 0; k< snake_.getElements().getSegmentsWithFood().size(); k++){
                    if(snake_.getElements().getSegmentsWithFood()[k].getXCoordinate() == j &&
                            snake_.getElements().getSegmentsWithFood()[k].getYCoordinate() == i){
                        isFoodHere = true;
                        break;
                    }
                }
                for(auto & it : snake_.getElements().getSegmentsWithObstacles()){
                    if(it.getXCoordinate() == j && it.getYCoordinate() == i){
                        isObstacleHere = true;
                        break;
                    }
                }
                if(isFoodHere){std::cout<<'F';}
                else if(isSnakeHere){std::cout<<'O';}
                else if(isObstacleHere){std::cout<<'X';}
                else std::cout<<' ';
            }

        }

        std::cout<<std::endl;
    }
    std::cout<<"O --> snake\nF --> food\nX --> obstacle\n# --> wall\n\nPOINTS: "<<this->snake_.points<<'\n'<<"Rapid: "<<this->rapid<<'\n';
}

void Game::runGame() {

    Snake::Direction currDir = Snake::Direction::UP;
    while(!snake_.checkCollision()){
        std::this_thread::sleep_for(std::chrono::milliseconds(rapid));

        //rapid = rapid - 0.05 * rapid;

        snake_.setNewPositionsAfterMovement(currDir);

        if(_kbhit()){
            char dir = getch();
            switch (dir){
                case'w':
                    if(currDir != Snake::Direction ::DOWN) {
                        snake_.setNewPositionsAfterMovement(Snake::Direction ::UP);
                        currDir = Snake::Direction ::UP;
                    }
                    break;
                case 'a':
                    if(currDir != Snake::Direction ::RIGHT) {
                        snake_.setNewPositionsAfterMovement(Snake::Direction ::LEFT);
                        currDir = Snake::Direction ::LEFT;
                    }
                    break;
                case's':
                    if(currDir != Snake::Direction ::UP) {
                        snake_.setNewPositionsAfterMovement(Snake::Direction ::DOWN);
                        currDir = Snake::Direction ::DOWN;
                    }
                    break;
                case 'd':
                    if(currDir != Snake::Direction ::LEFT) {
                        snake_.setNewPositionsAfterMovement(Snake::Direction ::RIGHT);
                        currDir = Snake::Direction ::RIGHT;
                    }
                    break;
                default:
                    break;

            }
        }

        this->snake_.riseUp(rapid);
        this->snake_.afterMeetWall();

        displaySnakeAndPlane();

    }
    std::cout<<"GAME OVER"<<std::endl;
    system("pause");
}

void Game::increaseRapid() {

    if(this->snake_.points > previousPoints){
        this->rapid = this->rapid - (this->rapid/this->snake_.points);
        previousPoints = this->snake_.points;
    }
}

Game::Game() = default;
