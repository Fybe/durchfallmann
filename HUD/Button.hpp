#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
public:
	Button();
	Button(Button const &other) = delete;
	Button(std::string str);
	~Button();
	
	void setString(std::string &str);
	std::string getString() const;

	void setFont(sf::Font const &font);
	sf::Font const &getFont() const;

	void update(float frametime);

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
private:
	sf::Text *pText;
	sf::Sprite *pBackground;
	sf::Texture *pTextureNormal;
	sf::Texture *pTextureHover;
	sf::Texture *pTexturePressed;
};
