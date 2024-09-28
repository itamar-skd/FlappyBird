#include "../inc/Graph.h"
#include <iostream>
#include <string>
#include <cstdlib>

Graph::Graph(uint8_t graphLength, uint8_t birdHeight)
	: __graphLength(graphLength)
	, __bird(new Bird(birdHeight))
	, __poles()
{
	this->addPole();
}

Graph::~Graph()
{
	delete this->__bird;
	this->__bird = nullptr;
}

bool Graph::printGraph()
{
	system("cls");
	std::string res{""};
	bool crashed{ false };
	bool hasBird{ false };
	bool hasBlock{ false };

	for (size_t i{ 0 }; i < this->__graphLength; i++)
	{
		for (size_t j{ 0 }; j < this->__graphLength; j++)
		{
			hasBird = (j == 2 && this->__bird->height() == i);

			hasBlock = false;
			for (Pole* pole : this->__poles)
			{
				if (pole->hasBlockAt(j, i, this->__graphLength))
				{
					hasBlock = true;
					break;
				}
			}

			if (!crashed)
				crashed = hasBird && hasBlock;

			if (hasBlock)
			{
				res += (char)254u;
				continue;
			}

			if (hasBird)
			{
				res += "*";
				continue;
			}

			res += " ";
		}

		res += '\n';
	}

	std::cout << res;
	return crashed;
}

void Graph::moveGraph()
{
	if (this->__poles.size() == 0)
		return;

	std::vector<Pole*>::iterator iter;
	for (iter = this->__poles.begin(); iter != this->__poles.end(); iter++)
	{
		(*iter)->setStartIndex((*iter)->startIndex() - 1);
	}

	Pole*& firstPole = this->__poles.at(0);
	if ((firstPole->startIndex() + firstPole->width() - 1) < 0)
	{
		delete firstPole;
		firstPole = nullptr;
		this->__poles.erase(this->__poles.begin());
	}

	Pole*& lastPole = this->__poles.at(this->__poles.size() - 1);
	if (this->__graphLength - (lastPole->startIndex() + lastPole->width() - 1) == 10)
	{
		this->addPole();
	}
}

void Graph::birdJump()
{
	if (this->__bird->height() == 0)
		return;

	this->__bird->setHeight(this->__bird->height() - 1);
}

bool Graph::birdFall()
{
	this->__bird->setHeight(this->__bird->height() + 1);
	if (this->__bird->height() >= this->__graphLength)
		return true;
	
	return false;
}

void Graph::addPole()
{
	srand(time(0));
	uint8_t lowerHeight = rand() % this->__graphLength / 2;
	uint8_t upperHeight = this->__graphLength - (lowerHeight + 3);
	uint8_t width = rand() % 3 + 1;

	this->__poles.push_back(new Pole(lowerHeight, upperHeight, width, __graphLength - 1));
}