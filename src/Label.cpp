#include "Label.h"

Label::Label(sf::String text, sf::Vector2f position, int duration) {
   setString(text);
   setPosition(position);
   this->duration = duration;
}

void Label::update() {
}
