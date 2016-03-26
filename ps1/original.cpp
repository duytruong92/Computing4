#include "original.hpp"
#include <iostream>

using namespace std;

int main(int argc,char* argv[]) 
{
	if(argc < 3)
	{
		cout<< "you need to input Window size and times"<<endl;
		exit(1);
	}
	sf::RenderWindow window(sf::VideoMode(atoi(argv[1]),atoi( argv[1])),"Square");
	square square(atoi(argv[2]), atoi(argv[1]));
	while (window.isOpen()) 
	{
	sf::Event event;
	while (window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) 
		{
			window.close();
		}
	}
		window.clear();
		window.draw(square);
		window.display();
	}
	return 0;
}
