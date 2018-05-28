#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Exception.hpp"


class Durchfallmann
{
public:
	Durchfallmann(uint32_t width, uint32_t height);
	~Durchfallmann();

	void init();
	void run();

private:
	uint32_t width;
	uint32_t height;
	sf::RenderWindow *pWindow;

	void draw();
};
