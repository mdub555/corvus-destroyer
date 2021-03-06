/* Main file for Asteroids game clone. This is a very rudementary start of the clone and will be
 * expanded upon soon in the future. All it does right now it make a rock and allow the rock to be
 * split when the space bar is pressed.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "Asteroids.h"
#include "util/flags.h"

// must add additional cases when more modes are added
void setMode(Modes mode, bool value) {
   std::string modeName;
   switch (mode) {
   case Modes::DEBUG:
      modeName = "debug";
      break;
   case Modes::GOD:
      modeName = "god";
      break;
   default:
      printf("[ERROR] Must add more cases to the setMode() function.\n");
      break;
   }
   printf("Setting %s mode to %s\n", modeName.c_str(), value ? "true" : "false");
   MODES[mode] = value;
}

// loads the font and then plays the game
int main(int argc, char** argv) {
   FlagOptions flags = parse_flags(argc, argv);
   setMode(Modes::GOD, flags.godmode);
   setMode(Modes::DEBUG, flags.debug);
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
   currentState.push(GameState::GAME);
   window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bullet Breaker!");
   currentLevel = 1;
   lives = FULL_LIVES;

   menus[GameState::MAIN_MENU]  = new PauseMenu();
   menus[GameState::PAUSE_MENU] = new PauseMenu();
   menus[GameState::PAUSE_MENU]->setFont(myFont);
   menus[GameState::GAMEOVER]   = new PauseMenu();
   menus[GameState::CREDITS]    = new PauseMenu();

   for (int i = 0; i < 4; i++) buttonsPressed[i] = false;

   livesLabel.setFont(myFont);
   livesLabel.setPosition(10, 10);
   livesLabel.setFillColor(sf::Color::White);
   updateLivesLabel();
}

void Asteroids::playGame() {
   update();
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
   bullets.clear();
   ship.respawn();
   return;
}

bool Asteroids::levelEnded() {
   if (rocks.size() == 0) return true;
   return false;
}

void Asteroids::update() {
   if (lives < 0) {
      currentState.push(GameState::GAMEOVER);
   }
   if (currentState.top() == GameState::GAME) {
      if(levelEnded()) {
         startLevel(currentLevel++);
      }
      updateShip();
      updateRocks();
      updateBullets();
   }
   return;
}

void Asteroids::draw() {
   window->clear();

   switch (currentState.top()) {
   case GameState::GAME:
      drawGame();
      break;
   case GameState::MAIN_MENU:
      menus[PAUSE_MENU]->draw(window);
      break;
   case GameState::PAUSE_MENU:
      drawGame();
      menus[PAUSE_MENU]->draw(window);
      break;
   case GameState::GAMEOVER:
      drawGameOver();
      break;
   case GameState::CREDITS:
      drawCredits();
      break;
   default:
      break;
   }

   window->display();
   return;
}

void Asteroids::drawGame() {
   drawBullets();
   drawRocks();
   drawShip();
   drawLives();
}

void Asteroids::checkEvent() {
   sf::Event event;
   while (window->pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
         window->close();
         break;
      case sf::Event::KeyPressed:
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
         || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
         }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            buttonsPressed[KeyButtons::SPACE] = true;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            buttonsPressed[KeyButtons::RIGHT] = true;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            buttonsPressed[KeyButtons::LEFT] = true;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            buttonsPressed[KeyButtons::UP] = true;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            buttonsPressed[KeyButtons::DOWN] = true;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            buttonsPressed[KeyButtons::ENTER] = true;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            if (currentState.top() == GameState::PAUSE_MENU) {
               currentState.pop();
            } else {
               currentState.push(GameState::PAUSE_MENU);
            }
         }
         break;
      case sf::Event::KeyReleased:
         switch (event.key.code) {
         case (sf::Keyboard::Space):
            buttonsPressed[KeyButtons::SPACE] = false;
         case (sf::Keyboard::Right):
            buttonsPressed[KeyButtons::RIGHT] = false;
         case (sf::Keyboard::Left):
            buttonsPressed[KeyButtons::LEFT] = false;
         case (sf::Keyboard::Up):
            buttonsPressed[KeyButtons::UP] = false;
         case (sf::Keyboard::Down):
            buttonsPressed[KeyButtons::DOWN] = false;
         case (sf::Keyboard::Return):
            buttonsPressed[KeyButtons::ENTER] = false;
         default:
            break;
         }
         break;
      default:
         break;
      }
   }
   return;
}

void Asteroids::applyEvents() {
   switch (currentState.top()) {
   case GameState::GAME:
      if (buttonsPressed[KeyButtons::LEFT]) ship.setRotate(-1);
      if (buttonsPressed[KeyButtons::RIGHT]) ship.setRotate(1);
      if (buttonsPressed[KeyButtons::LEFT] == buttonsPressed[KeyButtons::RIGHT])
         ship.setRotate(0); // if both are on or both off, don't turn
      if (buttonsPressed[KeyButtons::UP]) ship.startAccel();
      else ship.stopAccel();
      if (buttonsPressed[KeyButtons::SPACE] &&
          bulletClock.getElapsedTime().asMilliseconds() > SHOOT_DELAY) {
         bulletClock.restart();
         shoot();
      }
      break;
   case GameState::PAUSE_MENU:
      if (buttonsPressed[KeyButtons::UP]) menus[GameState::PAUSE_MENU]->navigateUp();
      if (buttonsPressed[KeyButtons::DOWN]) menus[GameState::PAUSE_MENU]->navigateDown();
      if (buttonsPressed[KeyButtons::ENTER])
         handleMenu(GameState::PAUSE_MENU, menus[GameState::PAUSE_MENU]->select());
      break;
   default:
      break;
   }
}

void Asteroids::handleMenu(const GameState state, const MenuAction action, const GameState newState) {
   switch (state) {
   case GameState::PAUSE_MENU:
      switch(action) {
      case MenuAction::POP:
         currentState.pop();
         break;
      case MenuAction::PUSH:
         currentState.push(newState);
         break;
      case MenuAction::EXIT:
         exit(EXIT_SUCCESS);
         break;
      default:
         break;
      }
      break;
   default:
      break;
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
   std::vector<Rock> newRocks = rocks.at(index).split();        // get the rocks from the split
   rocks.insert(rocks.end(), newRocks.begin(), newRocks.end()); // add it to the rock vector
   rocks.erase(rocks.begin()+index);                            // erase the rock that split
   return;
}

void Asteroids::shoot() {
   Bullet newBullet;                          // make a new bullet
   newBullet.setRotation(ship.getRotation()); // orient it the same way as the ship
   newBullet.setPosition(ship.getPosition()); // move it to the ship's location
   newBullet.addVelocity(ship.getVelocity());
   newBullet.update();                        // move the bullet outside of the ship
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
   std::string s = "Lives: " + std::to_string(lives);
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
