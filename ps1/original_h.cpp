#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include "original.hpp"
//overload draw function
void square::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(sq, states);
	square_rec(size * 0.5, 0.5 * size, 0.25 * size, times, target, states);
}
//define the value for square
square::square(int r, int size_i) 
{
	times = r;
	size = size_i;
	length = size_i;
	sq.setPointCount(4);
	sq.setPoint(0, sf::Vector2f(length / 2, 0));
	sq.setPoint(1, sf::Vector2f(0, length / 2));
	sq.setPoint(2, sf::Vector2f(length / 2, (length)));
  	sq.setPoint(3, sf::Vector2f((length), length / 2));
  	sq.setFillColor(sf::Color::Red);
}

square::~square() 
{
}
//fill the square
void square::filledSquare(sf::Vector2f set_point[4], sf::RenderTarget& target,sf::RenderStates states) const 
{
	sf::ConvexShape Square;
	Square.setPointCount(4);
	Square.setPoint(0, set_point[0]);
	Square.setPoint(1, set_point[1]);
	Square.setPoint(2, set_point[2]);
	Square.setPoint(3, set_point[3]);
	Square.setFillColor(sf::Color::White);
	Square.setOutlineColor(sf::Color::Black);
	Square.setOutlineThickness(1);
	Square.setPosition(0, (length - (2 * set_point[0].y)));
	target.draw(Square, states);
}

void square::square_rec(double x, double y, double s, int count,sf::RenderTarget& target, sf::RenderStates states) const 
{
	sf::Vector2f set_next_points[4];
	if (count == 0) 
	{
		return;
	} 
	else
	{
		// top right
		set_next_points[0].x = (x + s);
		set_next_points[0].y = (y + s);
		// bot right
		set_next_points[1].x = (x + s);
		set_next_points[1].y = (y + (s * 3));
		// bot left
		set_next_points[2].x = (x - s);
		set_next_points[2].y = (y + (s * 3));
		// top left
		set_next_points[3].x = (x - s);
		set_next_points[3].y = (y + s);
		filledSquare(set_next_points, target, states);
		square_rec(x,y, (s / 3), count - 1, target, states);
		square_rec(x+s,y+s, (s / 3), count - 1, target, states);
		square_rec(x-s,y-s, (s / 3), count - 1, target, states);	
		square_rec(x-s,y+s, (s / 3), count - 1, target, states);
		square_rec(x+s,y-s, (s / 3), count - 1, target, states);
	}
}
