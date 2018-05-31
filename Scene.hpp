#pragma once
#include <SFML/Graphics.hpp>


class Scene : public sf::Drawable
{
public:
	Scene();
	virtual ~Scene();

	void init();
	void destroy();

	// NOTE: This class neither does nor should not free the memory of the returned scene upon destruction.
	virtual Scene *getNextScene() = 0;

protected:
	virtual void onInit() = 0;
	virtual void onDestroy() = 0;
	virtual void update(float frametime) = 0;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

private:
	bool isInitialized;
};
