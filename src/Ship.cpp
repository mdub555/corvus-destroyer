/* Ship class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Ship.h"
#include <cmath>

// default constructor. the Ship is made of a rectangle and two circles.
Ship::Ship(const sf::Vector2f& position) {
   rotation = 0;
   accel = false;
   setPosition(position);
   inGodMode = false;

   setOrigin(sf::Vector2f(HEIGHT/3, WIDTH/2));
   setRotation(-90);

   setOutlineThickness(1);
   outlineColor = sf::Color::White;
   setOutlineColor(outlineColor);
   setFillColor(sf::Color::Transparent);
}

void Ship::update() {
   rotate(rotation*ROTATION_SPEED);
   accelerate();
   Object::update();
   validateSpeed();
   return;
}

void Ship::setRotate(int direction) {
   rotation = direction;
   return;
}

void Ship::stopAccel() {
   accel = false;
}

void Ship::startAccel() {
   accel = true;
}

void Ship::accelerate() {
   if (accel) {
      setAcceleration(sf::Vector2f(ACCELERATION*cos(getRotation()*PI/180), ACCELERATION*sin(getRotation()*PI/180)));
   } else {
      setAcceleration(sf::Vector2f(0, 0));
   }
   return;
}

// returns the height of the Ship
double Ship::getHeight() const {
   return HEIGHT;
}

// returns the width of the Ship
double Ship::getWidth() const {
   return WIDTH;
}

void Ship::validateSpeed() {
   double xVel = getVelocity().x;
   double yVel = getVelocity().y;
   if (xVel > MAX_VELOCITY)  setVelocity(sf::Vector2f( MAX_VELOCITY, yVel));
   if (xVel < -MAX_VELOCITY) setVelocity(sf::Vector2f(-MAX_VELOCITY, yVel));
   if (yVel > MAX_VELOCITY)  setVelocity(sf::Vector2f(xVel,  MAX_VELOCITY));
   if (yVel < -MAX_VELOCITY) setVelocity(sf::Vector2f(xVel, -MAX_VELOCITY));
   return;
}

void Ship::destroyAnimation() {
   return;
}

void Ship::respawnInvinsible() {
   respawn();
   godMode(1500);
   return;
}

void Ship::respawn() {
   setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
   setRotation(-90);
   setVelocity(sf::Vector2f(0, 0));
   return;
}

std::size_t Ship::getPointCount() const {
   return 4;
}

sf::Vector2f Ship::getPoint(std::size_t index) const {
   switch (index) {
      default:
      case 0: return sf::Vector2f(HEIGHT, WIDTH/2);
      case 1: return sf::Vector2f(0, WIDTH);
      case 2: return sf::Vector2f(HEIGHT/5, WIDTH/2);
      case 3: return sf::Vector2f(0, 0);
   }
}
