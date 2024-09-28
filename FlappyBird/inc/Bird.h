#pragma once
#include <stdint.h>

class Bird
{
private:
	uint8_t __height;

public:
	Bird(uint8_t height);
	~Bird() = default;

public:
	uint8_t height();
	void setHeight(uint8_t height);
};

