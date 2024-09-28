#include "inc/FlappyBird.h";
#include <iostream>


int main()
{
    FlappyBird game{ 17 };

    while (game.keepAlive())
    {

    }

    std::cout << "you lose";
}