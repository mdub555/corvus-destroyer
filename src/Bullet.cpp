/* Bullet class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Bullet.h"

#include <math.h>

// default constructor
Bullet::Bullet(const sf::Vector2f& position) {
   // size and position
   setSize(sf::Vector2f(WIDTH, HEIGHT));
   setPosition(position);
   setOrigin(sf::Vector2f(WIDTH/2, HEIGHT/2));

   // format instructions
   setOutlineThickness(1);
   outlineColor = sf::Color::White;
   setOutlineColor(outlineColor);
   setFillColor(sf::Color::Transparent);
}

void Bullet::addVelocity(const sf::Vector2f& velocity) {
   setVelocity(getVelocity() + velocity);
   return;
}

bool Bullet::hit(const Rock& rock) const {
   double xDist = rock.getPosition().x - getPosition().x;
   double yDist = rock.getPosition().y - getPosition().y;
   double radius = rock.getRadius();
   if (xDist*xDist + yDist*yDist < radius*radius) return true;
   return false;
}

void Bullet::setRotation(float angle) {
   Object::setRotation(angle);
   setVelocity(sf::Vector2f(BULLET_SPEED*cos(angle*PI/180), BULLET_SPEED*sin(angle*PI/180)));
   return;
}

int Bullet::timeAlive() const {
   return clock.getElapsedTime().asMilliseconds();
}

void Bullet::setSize(const sf::Vector2f& size) {
   m_size = size;
   update();
}

const sf::Vector2f& Bullet::getSize() const {
   return m_size;
}

unsigned int Bullet::getPointCount() const override {
   return 4;
}

sf::Vector2f Bullet::getPoint(unsigned int index) const override {
   switch (index) {
      default:
      case 0: return sf::Vector2f(0, 0);
      case 2: return sf::Vector2f(m_size.x, m_size.y);
      case 3: return sf::Vector2f(0, m_size.y);
   }
}
