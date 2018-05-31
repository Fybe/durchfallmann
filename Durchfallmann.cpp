#include "Durchfallmann.hpp"


Durchfallmann::Durchfallmann(uint32_t width, uint32_t height, uint32_t framerateLimit)
	: width(width), height(height), framerateLimit(framerateLimit), pWindow(nullptr), pCurrentScene(nullptr)
{}

Durchfallmann::~Durchfallmann()
{
	delete pWindow;
}

void Durchfallmann::init()
{
	pWindow = new sf::RenderWindow(sf::VideoMode(width,height), "Durchfallmann", sf::Style::Titlebar | sf::Style::Close);
	pCurrentScene = new MenuScene();

	if(framerateLimit == 0)
		pWindow->setVerticalSyncEnabled(true);
	else
		pWindow->setFramerateLimit(framerateLimit);
}

void Durchfallmann::run()
{
	if (pWindow == nullptr)
		throw noWindowException;

	sf::Clock frametimeClock;
	while (pWindow->isOpen())
	{
		sf::Event event;
		while (pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pWindow->close();
		}

		// Update and draw the current scene
		pWindow->clear();
		pCurrentScene->Update(frametimeClock.getElapsedTime().asSeconds());
		frametimeClock.reset();
		pWindow->draw(pCurrentScene);
		pWindow->display();
	}
}

void Durchfallmann::draw()
{
}


