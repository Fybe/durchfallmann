#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>

#include "Exception.hpp"
#include "Scene.hpp"


class Durchfallmann
{
public:
	Durchfallmann(uint32_t width, uint32_t height, uint32_t framerateLimit);
	~Durchfallmann();

	void init();
	void run();

private:
	uint32_t width;
	uint32_t height;
	sf::RenderWindow *pWindow;

	uint32_t framerateLimit;

	Scene *pCurrentScene;
	

	void draw();
};
