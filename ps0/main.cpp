#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>



int main()
{
	int x=10;
	int y =10;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Duy Truong");
	// Load green circle
	sf:: CircleShape circle;
 	circle.setRadius(60);
	circle.setFillColor(sf::Color::Green);
  	circle.setOutlineColor(sf::Color::Green);
  	circle.setOutlineThickness(5);
  	circle.setPosition(10,10);
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("sprite.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	sprite.setPosition(x,y);
	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Hello World!!!", font, 50);
	text.setColor(sf::Color::Red); 
	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("nice_music.wav"))
		return EXIT_FAILURE;
	// Play the music
	music.play();
	// Start the game loop
	while (window.isOpen())
	{
	// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
			window.close();
			// Clear screen
			window.clear();
			//keep the sprite move
			sprite.move(x,0);
			// moving by key
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					sprite.move(-2*x,0);
									}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					sprite.move(x,0);
				}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					sprite.move(0,-y);
				}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					sprite.move(0,y);
				}
			//change the character
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					if (!texture.loadFromFile("sprite.png"))
					return EXIT_FAILURE;
					sf::Sprite sprite(texture);
				}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					if (!texture.loadFromFile("sprite2.png"))
					return EXIT_FAILURE;
					sf::Sprite sprite(texture);
				}



			// Draw the sprite
			
			window.draw(circle);
			window.draw(sprite);
			// Draw the string
			window.draw(text);
			// Update the window
			window.display();
		}
	}
	return EXIT_SUCCESS;
}

