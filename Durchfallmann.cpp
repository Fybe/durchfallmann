#include "Durchfallmann.hpp"


Durchfallmann::Durchfallmann(uint32_t width, uint32_t height)
	: width(width), height(height), pWindow(nullptr)
{}

Durchfallmann::~Durchfallmann()
{
	delete pWindow;
}

void Durchfallmann::init()
{
	pWindow = new sf::RenderWindow(sf::VideoMode(width,height), "Durchfallmann");
}

void Durchfallmann::run()
{
	if (pWindow == nullptr)
		throw noWindowException;
	
	while (pWindow->isOpen())
	{
		sf::Event event;
		while (pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pWindow->close();
		}

		pWindow->clear();
		draw();
		pWindow->display();
	}
}

void Durchfallmann::draw()
{
}
