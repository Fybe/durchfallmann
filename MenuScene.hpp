#pragma once
#include "Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	virtual Scene *getNextScene() override;
	virtual void update(float frametime) override;

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	sf::Font *pFont;
	sf::Text *pLoadingText;
};
