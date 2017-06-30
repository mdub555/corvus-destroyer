#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;

#include "Rock.h"
#include "Ship.h"
#include "Bullet.h"
#include "GameState.h"
#include "Constants.h"
#include "Menu.h"

class Asteroids {
private:
  static const int FULL_LIVES = 4;
  Text livesLabel;
  void updateLivesLabel();
  int lives;

  int currentLevel;
  static const int NUM_LEVELS = 5;

  Menu mainMenu;
  Menu pauseMenu;

  Ship ship;
  vector<Rock> rocks;
  vector<Bullet> bullets;
  stack<GameState> currentState;
  Clock bulletClock;
  static const int SHOOT_DELAY = 250;
  static const int BULLET_LIFETIME = 1250;

  Font myFont;

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
  void setFPS(int FPS);
  bool isOpen() const ;

  bool upPressed;
  bool leftPressed;
  bool rightPressed;
  bool spacePressed;

  RenderWindow* window;
};

#endif
