#include "LevelScene.hpp"


LevelScene::LevelScene()
{
	pPlayerTexture = new sf::Texture();
	pPlayerTexture->loadFromFile("assets/player/durchfallmann.png");
	pPlayer = new sf::Sprite(*pPlayerTexture);
	pPlayer->setOrigin(static_cast<sf::Vector2f>(pPlayerTexture->getSize()) * 0.5f);

	displayRatio = 1.f;
	playerVelocity = sf::Vector2f(0.f, 800.f);
	playerPosition = sf::Vector2f(0.f, -0.7f);
}
LevelScene::~LevelScene()
{}

Scene *LevelScene::getNextScene()
{
	return nullptr;
}

void LevelScene::update(float frametime, sf::Vector2u const &windowSize)
{
	displayRatio = windowSize.x / windowSize.y;
	updatePlayer(frametime, windowSize);
}

void LevelScene::updatePlayer(float frametime, sf::Vector2u const &windowSize)
{
	sf::Vector2f playerAccel;
	sf::Vector2f n_x(1.f, 0.f);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		playerAccel = -n_x;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		playerAccel =  n_x;

	playerVelocity += playerAccel * frametime; 
	playerPosition += playerVelocity * frametime;

	if(playerPosition.x > displayRatio)
		playerPosition = sf::Vector2f(displayRatio, playerPosition.y);
	else if(playerPosition.x < -displayRatio)
		playerPosition = sf::Vector2f(-displayRatio, playerPosition.y);

	float alpha = std::atan2(playerVelocity.y, playerVelocity.x);
	pPlayer->setRotation(alpha * 180.f / 3.14159f);

	// Scale coordinates
	playerPosition *= static_cast<float>(windowSize.y);
}

void LevelScene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{}
