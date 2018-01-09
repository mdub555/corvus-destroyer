#include "Button.h"
#include <stdio.h>

// TODO: at button resize, setting text, or initialization, do something to put the origin of the
// rectangle in the center of the rectangle. at the moment, this is not being done in any logical
// way, and setting button position isn't working.

// if button has had their size specified, don't alter that.
// else, if button text or font changes, resize the button to fit
// on changing the buttons size in any way, center the text in the button

// if size is set, set label and center text
// else, set label, resize button and center text

// default constructor, nothing known
Button::Button() : Button(sf::Vector2f(10, 10)) {}

// create button with known label
Button::Button(std::string label) {
   setLabel(label);
   resizeToText();
   centerText();
   //setFillColor(sf::Color::Red);
   setOutlineColor(sf::Color::Red);
}

// create button with known size
Button::Button(const sf::Vector2f& size) {
   setLabel("");
   this->setSize(size);
   centerText();
}

void Button::setLabel(const std::string string) {
   label.setString(string);
   centerText();
   return;
}

void Button::centerText() {
   // make the text bounding box
   textBound = label.getLocalBounds();
   // set the origin as the middle of the bounding box. for some reason it works better with these
   // constants
   this->label.setOrigin(textBound.left + textBound.width/2.0f,
                         textBound.top  + textBound.height/2.0f);
   //label.setOrigin(textBound.width/2.f, textBound.height);
   label.setPosition(this->getPosition());
}

void Button::setLabelColor(const sf::Color color) {
   //label.setFillColor(color);
   label.setColor(color);
   return;
}

void Button::setFont(sf::Font &font) {
   label.setFont(font);
   resizeToText();
}

void Button::setPosition(sf::Vector2f position) {
   if (MODES[Modes::DEBUG]) printf("Setting position to: (%f, %f)\n", position.x, position.y);
   sf::RectangleShape::setPosition(position);
   centerText();
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

// resize button and put the origin in the center. do nothing with the text.
void Button::setSize(const sf::Vector2f& size) {
   sf::RectangleShape::setSize(size);
   this->setOrigin(size/2.f);
}

void Button::resizeToText() {
   textBound = label.getLocalBounds();
   sf::Vector2f temp(textBound.width, textBound.height);
   setSize(temp);
   centerText();
}

void Button::draw(sf::RenderWindow* window) {
   // draw button
   //window->draw(*this);

   // draw text
   window->draw(label);
   return;
}
