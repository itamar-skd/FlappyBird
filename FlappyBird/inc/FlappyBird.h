#pragma once

#include "Graph.h";
#include <thread>
#include <chrono>

using namespace std::chrono;

class FlappyBird
{
private:
	Graph __graph;

	bool __keepAlive;
	std::thread __inputThrd;
	std::thread __birdFallThrd;
	std::thread __poleAdvanceThrd;

	time_point<system_clock> __lastInput;

public:
	FlappyBird(uint8_t graphLength);
	~FlappyBird();

public:
	bool keepAlive();

private:
	void __input();
	void __birdFall();
	void __poleAdvance();
};

