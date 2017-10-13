/* Main file for Asteroids game clone. This is a very rudementary start of the clone and will be
 * expanded upon soon in the future. All it does right now it make a rock and allow the rock to be
 * split when the space bar is pressed.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Asteroids.h"

// loads the font and then plays the game
int main() {
  srand(time(NULL));

  Asteroids game;
  game.setFPS(FRAMERATE);

  while (game.isOpen()) {
    game.playGame();
  }
  return 0;
}

Asteroids::Asteroids() {
  if (!myFont.loadFromFile("data/slkscr.ttf")) return;
  currentState.push(GAME);
  window = new RenderWindow(VideoMode(WINDOW_X, WINDOW_Y), "Bullet Breaker!");
  currentLevel = 1;
  lives = FULL_LIVES;

  livesLabel.setFont(myFont);
  livesLabel.setPosition(10, 10);
  livesLabel.setColor(Color::White);
  updateLivesLabel();
}

void Asteroids::playGame() {
  if (currentState.top() == GameState::GAME) {
    update();
  }
  checkEvent();
  applyEvents();
  draw();
  return;
}

void Asteroids::startLevel(int level) {
  int numRocks = 2*level-1;
  for (int i = 0; i < numRocks; ++i) {
    rocks.push_back(Rock(3));
  }
  ship.godMode(2000);
  return;
}

bool Asteroids::levelEnded() {
  if (rocks.size() == 0) return true;
  return false;
}

void Asteroids::update() {
  if(levelEnded()) {
    startLevel(currentLevel++);
  }
  updateShip();
  updateRocks();
  updateBullets();
  return;
}

void Asteroids::draw() {
  window->clear();

  if (currentState.top() == GameState::GAME) {
    drawBullets();
    drawRocks();
    drawShip();
    drawLives();
  } else if (currentState.top() == GameState::MAIN_MENU) {
    //mainMenu.draw(window);
  } else if (currentState.top() == GameState::PAUSE_MENU) {
    //pauseMenu.draw(window);
  } else if (currentState.top() == GameState::GAMEOVER) {
    drawGameOver();
  } else {
    drawCredits();
  }

  window->display();
  return;
}

void Asteroids::checkEvent() {
  Event event;
  while (window->pollEvent(event)) {
    switch (event.type) {
    case Event::Closed:
      window->close();
      break;
    case Event::KeyPressed:
      if (Keyboard::isKeyPressed(Keyboard::Q)
      || Keyboard::isKeyPressed(Keyboard::Escape)) {
        window->close();
      }

      if (Keyboard::isKeyPressed(Keyboard::Space)) {
        spacePressed = true;
      }
      if (Keyboard::isKeyPressed(Keyboard::Right)) {
        rightPressed = true;
      }
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
        leftPressed = true;
      }
      if (Keyboard::isKeyPressed(Keyboard::Up)) {
        upPressed = true;
      }
      break;
    case Event::KeyReleased:
      if (event.key.code == Keyboard::Space) {
        spacePressed = false;
      }
      if (event.key.code == Keyboard::Right) {
        rightPressed = false;
      }
      if (event.key.code == Keyboard::Left) {
        leftPressed = false;
      }
      if (event.key.code == Keyboard::Up) {
        upPressed = false;
      }
      break;
    default:
      break;
    }
  }
  return;
}

void Asteroids::applyEvents() {
  if (leftPressed) ship.setRotate(-1);
  if (rightPressed) ship.setRotate(1);
  if (leftPressed == rightPressed) ship.setRotate(0); // if both are on or both off, don't turn
  if (upPressed) ship.startAccel();
  else ship.stopAccel();
  if (spacePressed && bulletClock.getElapsedTime().asMilliseconds() > SHOOT_DELAY) {
    bulletClock.restart();
    shoot();
  }
}

void Asteroids::setFPS(int FPS) {
  window->setFramerateLimit(FPS);
  return;
}

bool Asteroids::isOpen() const {
  return window->isOpen();
}

void Asteroids::splitRock(int index) {
  vector<Rock> newRocks = rocks.at(index).split();             // get the rocks from the split
  rocks.insert(rocks.end(), newRocks.begin(), newRocks.end()); // add it to the rock vector
  rocks.erase(rocks.begin()+index);                            // erase the rock that split
  return;
}

void Asteroids::shoot() {
  Bullet newBullet;                          // make a new bullet
  newBullet.setRotation(ship.getRotation()); // orient it the same way as the ship
  newBullet.setPosition(ship.getPosition()); // move it to the ship's location
  newBullet.addVelocity(ship.getVelocity());
  bullets.push_back(newBullet);              // add it to the bullet vector
  return;
}

void Asteroids::drawBullets() {
  for (unsigned int i = 0; i < bullets.size(); i++) {
    bullets[i].draw(window);
  }
  return;
}

void Asteroids::drawRocks() {
  for (unsigned int i = 0; i < rocks.size(); i++) {
    rocks[i].draw(window);
  }
  return;
}

void Asteroids::drawShip() {
  ship.draw(window);
  return;
}

void Asteroids::drawLives() {
  window->draw(livesLabel);
  return;
}

// TODO
void Asteroids::drawGameOver() {
  return;
}

// TODO
void Asteroids::drawCredits() {
  return;
}

void Asteroids::updateLivesLabel() {
  string s = "Lives: " + to_string(lives);
  livesLabel.setString(s);
  return;
}

void Asteroids::updateRocks() {
  // move all the rocks
  for (unsigned int i = 0; i < rocks.size(); ++i) {
    rocks.at(i).Object::update();
  }

  // check if the rock got hit by a bullet
  for (unsigned int i = 0; i < rocks.size(); ++i) {
    for (unsigned int j = 0; j < bullets.size(); ++j) {
      if (bullets.at(j).hit(rocks.at(i))) {
        splitRock(i);
        bullets.erase(bullets.begin()+j);
        break;
      }
    }
  }
  return;
}

void Asteroids::updateShip() {
  ship.update();
  for (unsigned int i = 0; i < rocks.size(); ++i) {
    if (rocks[i].checkShipCollision(ship)) {
      destroyShip();
    }
  }
  return;
}

// TODO finish the ship destroy method
void Asteroids::destroyShip() {
  ship.destroyAnimation();
  lives--;
  updateLivesLabel();
  ship.respawnInvinsible();
}

void Asteroids::updateBullets() {
  for (unsigned int i = 0; i < bullets.size(); ++i) {
    bullets.at(i).Object::update();
    if (bullets.at(i).timeAlive() > BULLET_LIFETIME) {
      bullets.erase(bullets.begin()+i);
      --i;
    }
  }
  return;
}
