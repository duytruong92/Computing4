#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "sierpinski.hpp"
//over load draw function
void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(triangle, states);
	sierpinski(0.5 * size, 0.0, 0.5 * size, times, target, states);
}

Sierpinski::Sierpinski(int r, int size_tr) 
{
	times = r;
	size = size_tr;
	length = size_tr;
	// sets the triangle to the size of the window
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(0, length));
	triangle.setPoint(1, sf::Vector2f(length, length));
	triangle.setPoint(2, sf::Vector2f((length / 2),(length - (sqrt(3) / 2) * length)));
	triangle.setFillColor(sf::Color::Blue);
}

Sierpinski::~Sierpinski() 
{
}

void Sierpinski::sierpinski(double x, double y, double s, int count,sf::RenderTarget& target,sf::RenderStates states) const 
{
	sf::Vector2f set_next_points[3];
	if (count == 0) 
	{  // causes segmentation error without
	return;
	} 
	else 
	{
// sets coords
		set_next_points[0].x = x;
		set_next_points[0].y = y;
		set_next_points[1].x = (x - (s / 2));
		set_next_points[1].y = (y - (sqrt(3) / 2) * s);
		set_next_points[2].x = (x + (s / 2));
		set_next_points[2].y = (y - (sqrt(3) / 2) * s);
// makes triangle
		filledTriangle(set_next_points, target, states);
// recursion
		sierpinski(x, y + ( (sqrt(3) / 2) * (s)), (s / 2),count - 1, target, states);
		sierpinski(x - (s / 2), y, (s / 2), count - 1, target, states);
		sierpinski(x + (s / 2), y, (s / 2), count - 1, target, states);
	}
}

void Sierpinski::filledTriangle(sf::Vector2f set_point[3],sf::RenderTarget& target,sf::RenderStates states) const 
{
  // creates a filled triangle
 	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, set_point[0]);
	triangle.setPoint(1, set_point[1]);
	triangle.setPoint(2, set_point[2]);
	triangle.setFillColor(sf::Color::White);
	triangle.setPosition(0, size - (2 * set_point[0].y));
	target.draw(triangle, states);
}
