#include "MenuScene.hpp"

MenuScene::MenuScene()
	: Scene()
{
	pFont = new sf::Font();
	pFont->loadFromFile("fonts/NotoSerif-Regular.ttf");

	pLoadingText = new sf::Text();
	pLoadingText->setFont(*pFont);
	pLoadingText->setFillColor(sf::Color::Black);
	pLoadingText->setString("Loading...");
	pLoadingText->setPosition(0.5f, 0.5f);
	pLoadingText->setOrigin(0.5f, 0.5f);
}
MenuScene::~MenuScene()
{
	delete pFont;
}

Scene *MenuScene::getNextScene()
{
	return new LevelScene();
}

void MenuScene::update(float frametime, sf::Vector2u const &windowSize)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		setDone();

	int32_t ms = clock.getElapsedTime().asMilliseconds();
	if(ms > 3200)
		this->setDone();
		clock.restart();

	if(ms > 2400)
		pLoadingText->setString("Loading...");
	else if(ms > 1600)
		pLoadingText->setString("Loading..");
	else if(ms > 800)
		pLoadingText->setString("Loading.");
	else
		pLoadingText->setString("Loading");
}

void MenuScene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*pLoadingText);
}
