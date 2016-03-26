#ifndef SIERPINSKI_HPP_
#define SIERPINSKI_HPP_

// incluced dependencies
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sierpinski : public sf::Drawable 
{
public:
	Sierpinski(int r, int size_tr);
	~Sierpinski();
	void filledTriangle(sf::Vector2f set_point[3], sf::RenderTarget& target,sf::RenderStates states) const;	
	void sierpinski(double x, double y, double s, int count,sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::ConvexShape triangle;
	int times;
	int size;
	int length;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
