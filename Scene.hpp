#pragma once
#include <SFML/Graphics.hpp>

class Scene : public sf::Drawable, public sf::Transformable
{
public:
	Scene();
	virtual ~Scene();

	// NOTE: This class neither does nor should free the memory of the returned scene upon destruction.
	virtual Scene *getNextScene() = 0;

	virtual void update(float frametime) = 0;

	bool isDone() const;

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

	void setDone();

private:
	bool done;
};
