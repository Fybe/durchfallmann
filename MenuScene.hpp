#pragma once
#include "Scene.hpp"
#include "LevelScene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	virtual Scene *getNextScene() override;
	virtual void update(float frametime, sf::Vector2u const &windowSize) override;

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	sf::Font *pFont;
	sf::Text *pLoadingText;

	sf::Clock clock;
};
