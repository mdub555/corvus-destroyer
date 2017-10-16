#ifndef _UTIL_H_
#define _UTIL_H_

#include <SFML/Graphics.hpp>

static const int FRAMERATE = 60;
static constexpr double PI = 3.14159265;
static const int WINDOW_WIDTH  = 1280;
static const int WINDOW_HEIGHT = 1000;
static const sf::Vector2f ROCK_SPAWN_POINTS[4] = { sf::Vector2f(100,100),
                                                   sf::Vector2f(WINDOW_WIDTH-100, 100),
                                                   sf::Vector2f(100, WINDOW_HEIGHT-100),
                                                   sf::Vector2f(WINDOW_WIDTH-100, WINDOW_HEIGHT-100) };

// put all the menu entries before other entries
enum GameState {
   MAIN_MENU, PAUSE_MENU, GAMEOVER, CREDITS, GAME
};

enum KeyButtons {
   UP, LEFT, RIGHT, SPACE
};

#endif
