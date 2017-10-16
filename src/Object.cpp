#include "Object.h"

Object::Object() {}

void Object::setVelocity(const sf::Vector2f& velocity) {
   m_velocity = velocity;
   return;
}

void Object::setAcceleration(const sf::Vector2f& acceleration) {
   m_acceleration = acceleration;
   return;
}

sf::Vector2f Object::getVelocity() const {
   return m_velocity;
}

sf::Vector2f Object::getAcceleration() const {
   return m_acceleration;
}

void Object::update() {
   m_velocity += m_acceleration;
   move(m_velocity);
   checkBounds();
   checkGodMode();
   return;
}

void Object::checkBounds() {
   float xPos = getPosition().x;
   float yPos = getPosition().y;
   if (xPos < 0) setPosition(sf::Vector2f(xPos+WINDOW_WIDTH, yPos));
   if (xPos >= WINDOW_WIDTH) setPosition(sf::Vector2f(xPos-WINDOW_WIDTH, yPos));
   if (yPos < 0) setPosition(sf::Vector2f(xPos, yPos+WINDOW_HEIGHT));
   if (yPos >= WINDOW_HEIGHT) setPosition(sf::Vector2f(xPos, yPos-WINDOW_HEIGHT));
   return;
}

void Object::draw(sf::RenderWindow* window) {
   float xPos = getPosition().x;
   float yPos = getPosition().y;
   if (inGodMode) {
      flash();
   }

   sf::FloatRect box = getGlobalBounds();
   if (box.left <= 0) {
      setPosition(xPos+WINDOW_WIDTH, yPos);
      window->draw(*this);
   }
   if (box.left+box.width > WINDOW_WIDTH) {
      setPosition(xPos-WINDOW_WIDTH, yPos);
      window->draw(*this);
   }
   if (box.top <= 0) {
      setPosition(xPos, yPos+WINDOW_HEIGHT);
      window->draw(*this);
   }
   if (box.top+box.height > WINDOW_HEIGHT) {
      setPosition(xPos, yPos-WINDOW_HEIGHT);
      window->draw(*this);
   }
   if (box.left <= 0 && box.top <= 0) {
      setPosition(xPos+WINDOW_WIDTH, yPos+WINDOW_HEIGHT);
      window->draw(*this);
   }
   if (box.left+box.width > WINDOW_WIDTH && box.top+box.height > WINDOW_HEIGHT) {
      setPosition(xPos-WINDOW_WIDTH, yPos-WINDOW_HEIGHT);
      window->draw(*this);
   }
   if (box.left <= 0 && box.top+box.height > WINDOW_HEIGHT) {
      setPosition(xPos+WINDOW_WIDTH, yPos-WINDOW_HEIGHT);
      window->draw(*this);
   }
   if (box.left+box.width > WINDOW_WIDTH && box.top <= 0) {
      setPosition(xPos-WINDOW_WIDTH, yPos+WINDOW_HEIGHT);
      window->draw(*this);
   }
   setPosition(xPos, yPos);
   window->draw(*this);
   return;
}

void Object::flash() {
   if (godModeTimer.getElapsedTime().asMilliseconds() % (2*flashDuration) < flashDuration) {
      setOutlineColor(sf::Color::Transparent);
   } else {
      setOutlineColor(outlineColor);
   }
   return;
}

void Object::godMode(int duration) {
   godModeTimer.restart();
   godModeDuration = duration;
   inGodMode = true;
   return;
}

void Object::checkGodMode() {
   if (godModeTimer.getElapsedTime().asMilliseconds() >= godModeDuration) {
      inGodMode = false;
   }
   return;
}

bool Object::isInGodMode() const {
   return inGodMode;
}
