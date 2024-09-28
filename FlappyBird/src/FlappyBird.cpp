#include "../inc/FlappyBird.h"
#include "../inc/defines.h"
#include <conio.h>

using namespace std::chrono_literals;

FlappyBird::FlappyBird(uint8_t graphLength)
	: __graph(graphLength, graphLength / 2)
	, __keepAlive(true)
	, __inputThrd(&FlappyBird::__input, this)
	, __birdFallThrd(&FlappyBird::__birdFall, this)
	, __poleAdvanceThrd(&FlappyBird::__poleAdvance, this)
	, __lastInput(system_clock::now())
{
	this->__graph.printGraph();
}

FlappyBird::~FlappyBird()
{
	this->__keepAlive = false;
	this->__inputThrd.join();
	this->__birdFallThrd.join();
	this->__poleAdvanceThrd.join();
}

bool FlappyBird::keepAlive()
{
	return this->__keepAlive;
}

void FlappyBird::__input()
{
	int input{ -1 };

	while (this->__keepAlive)
	{
		input = _getch();
		if (input != SPACE_BAR)
			continue;

		this->__graph.birdJump();
		this->__lastInput = system_clock::now();
	}
}

void FlappyBird::__birdFall()
{
	bool hitGround{ false };
	while (this->__keepAlive)
	{
		if (duration_cast<milliseconds>(system_clock::now() - __lastInput) > 500ms)
		{
			hitGround = this->__graph.birdFall();

			if (hitGround)
			{
				this->~FlappyBird();
			}
		}

		std::this_thread::sleep_for(0.5s);
	}
}

void FlappyBird::__poleAdvance()
{
	bool crashed{ false };

	while (this->__keepAlive)
	{
		std::this_thread::sleep_for(0.5s);
		this->__graph.moveGraph();
		crashed = this->__graph.printGraph();

		if (crashed)
			this->~FlappyBird();
	}
}