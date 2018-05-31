#include "Durchfallmann.hpp"


Durchfallmann::Durchfallmann(uint32_t width, uint32_t height, uint32_t framerateLimit)
	: width(width), height(height), framerateLimit(framerateLimit), pWindow(nullptr), pCurrentScene(nullptr)
{}

Durchfallmann::~Durchfallmann()
{
	delete pCurrentScene;
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
		throw Exception("window creation failed");

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
		pCurrentScene->update(frametimeClock.restart().asSeconds());
		if(pCurrentScene->isDone())
		{
			Scene *pNextScene = pCurrentScene->getNextScene();
			if(pNextScene == nullptr)
			{
				pWindow->close();
			}
			else
			{
				delete pCurrentScene;
				pCurrentScene = pNextScene;
			}
			continue;
		}

		pWindow->clear(sf::Color::White);
		pWindow->draw(*pCurrentScene);
		pWindow->display();
	}
}

void Durchfallmann::draw()
{
}


