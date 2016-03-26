#include "sierpinski.hpp"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{	
	if (argc < 3) 
	{
		cout << "You need to enter a window size and times.\n";
   		exit(1);
  	}
	sf::RenderWindow window(sf::VideoMode(atoi(argv[1]),atoi(argv[1])),"Sierpinski Triangle");
	Sierpinski sierpinski(atoi(argv[2]),atoi(argv[1]));
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
				break;
			}
		}
	window.clear();
	window.draw(sierpinski);
	window.display();
	}
	return 0;
}
