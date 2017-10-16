#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SFML/Graphics.hpp>

class Button : public sf::RectangleShape {
private:
   sf::Text label;
   sf::FloatRect textBound;

   void centerText();

public:
   Button();
   Button(const std::string label);
   Button(const sf::Vector2f& size);

   void setLabel(const std::string label);
   void setLabelColor(const sf::Color labelColor);
   void setFont(sf::Font &font);
   void setPosition(sf::Vector2f position);
   void setPosition(float x, float y);

   float getTextHeight() const;

   bool pressed(sf::Event event);
   void resize();
   void draw(sf::RenderWindow* window);
};

#endif
