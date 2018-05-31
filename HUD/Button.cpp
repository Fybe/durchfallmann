#include "Button.hpp"

Button::Button()
	: Button("")
{}
Button::Button(std::string str)
{
	pText = new sf::Text();
	pText->setString(str);
	pBackground = new sf::Sprite();
	pTextureNormal = new sf::Texture();
	pTextureHover = new sf::Texture();
	pTexturePressed = new sf::Texture();
}

Button::~Button()
{
	delete pText;
	delete pBackground;
	delete pTextureNormal;
	delete pTextureHover;
	delete pTexturePressed;
}

void Button::setString(std::string &str)
{ pText->setString(str); }
std::string Button::getString() const
{ return pText->getString(); }

void Button::setFont(sf::Font const &font)
{ pText->setFont(font); }
sf::Font const &Button::getFont() const
{ return *pText->getFont(); }

void Button::update(float frametime)
{}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{}
