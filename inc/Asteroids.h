#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Rock.h"
#include "Ship.h"
#include "Bullet.h"
#include "util/constants.h"
#include "Menu.h"
#include "PauseMenu.h"

// this is here because it needs to be defined in ONE file after the declaration in constants.h
bool MODES[NUM_MODES];

class Asteroids {
private:
   static const int FULL_LIVES = 4;
   sf::Text livesLabel;
   void updateLivesLabel();
   int lives;

   int currentLevel;
   static const int NUM_LEVELS = 5;

   Menu *menus[4];
   bool buttonsPressed[NUM_BUTTONS];

   Ship ship;
   std::vector<Rock> rocks;
   std::vector<Bullet> bullets;
   std::stack<GameState> currentState;
   sf::Clock bulletClock;
   static const int SHOOT_DELAY = 250;
   static const int BULLET_LIFETIME = 1250;

   sf::Font myFont;

   void drawGame();
   void drawBullets();
   void drawRocks();
   void drawShip();
   void drawLives();
   void drawGameOver();
   void drawCredits();
   void updateRocks();
   void updateShip();
   void updateBullets();
   void splitRock(int index);
   void shoot();
   void destroyShip();

public:
   Asteroids();

   void playGame();
   void startLevel(int level);
   bool levelEnded();
   void update();
   void draw();
   void checkEvent();
   void applyEvents();
   void handleMenu(const GameState state, const MenuAction action, const GameState newState = GAME);
   void setFPS(int FPS);
   bool isOpen() const ;


   sf::RenderWindow* window;
};

#endif
