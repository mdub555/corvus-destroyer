#include "Button.h"
#include <stdio.h>

Button::Button() : Button(sf::Vector2f(10, 10)) {}

Button::Button(std::string label) {
   setLabel(label);
   resize();
}

Button::Button(const sf::Vector2f& size) {
   setSize(size);
   setOrigin(sf::Vector2f(size.x/2, size.y/2));
}

void Button::setLabel(const std::string string) {
   label.setString(string);
   centerText();
   return;
}

void Button::centerText() {
   // make the text bounding box
   textBound = label.getLocalBounds();
   // set the origin as the middle of the bounding box
   label.setOrigin(textBound.left + textBound.width/2.0f,
                   textBound.top  + textBound.height/2.0f);
   label.setPosition(this->getOrigin());
}

void Button::setLabelColor(const sf::Color color) {
   label.setFillColor(color);
   return;
}

void Button::setFont(sf::Font &font) {
   label.setFont(font);
   resize();
}

void Button::setPosition(sf::Vector2f position) {
   sf::RectangleShape::setPosition(position);
   label.setPosition(position);
}

void Button::setPosition(float x, float y) {
   Button::setPosition(sf::Vector2f(x, y));
}

float Button::getTextHeight() const {
   return textBound.height;
}

bool Button::pressed(sf::Event event) {
   sf::Vector2f pressLocation = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
   if (getGlobalBounds().contains(pressLocation)) return true;
   return false;
}

void Button::resize() {
   centerText();
   printf("%f %f\n", textBound.width, textBound.height);
   this->setSize(sf::Vector2f(textBound.width + 10, textBound.height + 5));
}

void Button::draw(sf::RenderWindow* window) {
   // draw button
   window->draw(*this);

   // draw text
   window->draw(label);
   return;
}
