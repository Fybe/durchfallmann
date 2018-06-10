#include "Scene.hpp"
#include <cmath>


class LevelScene : public Scene
{
public:
	LevelScene();
	virtual ~LevelScene();

	virtual Scene *getNextScene() override;

	virtual void update(float frametime, sf::Vector2u const &windowSize) override;

	void updatePlayer(float frametime, sf::Vector2u const &windowSize);

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	
private:
	float displayRatio;
	
	sf::Sprite *pPlayer;
	sf::Texture *pPlayerTexture;

	sf::Vector2f playerPosition;
	sf::Vector2f playerVelocity;

};
