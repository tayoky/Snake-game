#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]){
    Game game;
    game.initialiseGame();
    game.runGame();
    game.exitGame();
    return 0;
}