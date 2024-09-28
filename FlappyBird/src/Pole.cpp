#include "../inc/Pole.h"

Pole::Pole(uint8_t lowerHeight, uint8_t upperHeight, uint8_t width, uint8_t startIndex)
	: __lowerHeight(lowerHeight)
	, __upperHeight(upperHeight)
	, __width(width)
	, __startIndex(startIndex)
{}

uint8_t Pole::lowerHeight()
{
	return this->__lowerHeight;
}

uint8_t Pole::upperHeight()
{
	return this->__upperHeight;
}

uint8_t Pole::width()
{
	return this->__width;
}

uint8_t Pole::startIndex()
{
	return this->__startIndex;
}

void Pole::setStartIndex(uint8_t startIndex)
{
	this->__startIndex = startIndex;
}

bool Pole::hasBlockAt(uint8_t index, uint8_t height, uint8_t totalPoleHeight)
{
	if (index < this->__startIndex)
		return false;

	if (index > (this->__startIndex + this->__width - 1))
		return false;

	if ((height > this->__upperHeight - 1) && (height < (totalPoleHeight - this->__lowerHeight)))
		return false;

	return true;
}