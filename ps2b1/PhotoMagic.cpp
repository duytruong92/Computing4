// pixels.cpp: 
// using SFML to load a file, manipulate its pixels, write it to disk
// Fred Martin, fredm@cs.uml.edu, Sun Mar  2 15:57:08 2014

// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "lfsr_class.hpp"

sf::Image transform(sf::Image  image, LFSR * m);

void displayImage(sf::RenderWindow *window, sf::RenderWindow *window2,
		  sf::Sprite sprite, sf::Sprite sprite2);
		  

int main(int argc, char *argv[])
{
  std:: string pic1, pic2;


  pic1 = argv[1];
  pic2 = argv[4];

  sf::Image image, image2;
  if (!image.loadFromFile(pic1))
    return -1;

  LFSR m(argv[2], std::atoi(argv[3]));
  
  image2 =  transform(image, &m);
  
  sf::Vector2u size =image.getSize();
  sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Input Image");
  sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output Image");
  
  

  sf::Texture texture;
  texture.loadFromImage(image);

  sf::Sprite sprite;
  sprite.setTexture(texture);

  
  sf::Texture texture2;
  texture2.loadFromImage(image2);

  sf::Sprite sprite2;
  sprite2.setTexture(texture2);
  
  
   if (!image2.saveToFile(pic2))
    return -1;

   displayImage(&window, &window2, sprite, sprite2);
   /*
   while (window.isOpen() && window2.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
      while (window2.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window2.close();
	}

      window.clear(sf::Color::White);
      window.draw(sprite);
      window.display();
      window2.clear(sf::Color::White);
      window2.draw(sprite2);
      window2.display();
    }
   */
  return 0;
}

sf::Image transform(sf::Image  image, LFSR * m)
{
       sf::Vector2u big = image.getSize();
       sf::Color p;
       for (int x=0; x<big.x; x++) {
	 for (int y= 0; y<big.y; y++)
	   {
	     p = image.getPixel(x, y);
	     p.r = p.r ^ m->generate(9);
	     p.g = p.g ^ m->generate(9);
	     p.b = p.b ^ m->generate(9);
	     image.setPixel(x, y, p);
	   }
       }
       return image;
}


void displayImage(sf::RenderWindow *window, sf::RenderWindow *window2,
		  sf::Sprite sprite, sf::Sprite sprite2)
{
  while (window->isOpen() && window2->isOpen())
    {
      sf::Event event;
      while (window->pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window->close();
	}
      while (window2->pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window->close();
	}

      window->clear(sf::Color::White);
      window->draw(sprite);
      window->display();
      window2->clear(sf::Color::White);
      window2->draw(sprite2);
      window2->display();
    }

}
