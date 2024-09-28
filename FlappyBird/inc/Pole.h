#pragma once
#include <stdint.h>

class Pole
{
private:
	uint8_t __lowerHeight;
	uint8_t __upperHeight;
	uint8_t __width;
	uint8_t __startIndex;

public:
	Pole(uint8_t lowerHeight, uint8_t upperHeight, uint8_t width, uint8_t startIndex);
	~Pole() = default;

public:
	uint8_t lowerHeight();
	uint8_t upperHeight();
	uint8_t width();
	uint8_t startIndex();
	void setStartIndex(uint8_t startIndex);

	bool hasBlockAt(uint8_t index, uint8_t height, uint8_t totalPoleHeight);
};

