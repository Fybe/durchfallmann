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
	return nullptr;
}

void MenuScene::update(float frametime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		setDone();
}

void MenuScene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*pLoadingText);
}
