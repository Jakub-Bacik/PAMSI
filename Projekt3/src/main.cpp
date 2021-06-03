#include <iostream>
#include "../inc/Matrix.hpp"
#include "../inc/GameLogic.hpp"


int main(){
    GameLogic gameLogic(3,3);
    gameLogic.FillTheMatrix();
    FunctionToShow(gameLogic);
    std::cout << gameLogic << std::endl;

   return 0;
}