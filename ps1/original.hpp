#ifndef ORIGIN_H
#define ORIGIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class square : public sf::Drawable {
 public:
  square(int r, int size_i);
  ~square();
  void filledSquare(sf::Vector2f set_point[4], sf::RenderTarget& target,
                  sf::RenderStates states) const;
  void square_rec(double x, double y, double s, int count,
               sf::RenderTarget& target, sf::RenderStates states) const;
  
 private:
  sf::ConvexShape sq;
  int times;
  int size;
  int length;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
