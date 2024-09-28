#pragma once
#include "Bird.h"
#include "Pole.h"
#include <vector>

class Graph
{
private:
	uint8_t __graphLength;

	Bird* __bird;
	std::vector<Pole*> __poles;

public:
	Graph(uint8_t graphLength, uint8_t birdHeight);
	~Graph();

public:
	bool printGraph();
	void moveGraph();
	void birdJump();
	bool birdFall();
	void addPole();
};

