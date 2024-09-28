#include "../inc/Bird.h"

Bird::Bird(uint8_t height)
	: __height(height)
{}

uint8_t Bird::height()
{
	return this->__height;
}

void Bird::setHeight(uint8_t height)
{
	this->__height = height;
}