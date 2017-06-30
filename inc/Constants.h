#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>
using namespace sf;

static const int FRAMERATE = 60;
static constexpr double PI = 3.14159265;
static const int WINDOW_X = 1280;
static const int WINDOW_Y = 1000;
static const Vector2f ROCK_SPAWN_POINTS[4] = { Vector2f(100,100),
											   Vector2f(WINDOW_X-100, 100),
											   Vector2f(100, WINDOW_Y-100),
											   Vector2f(WINDOW_X-100, WINDOW_Y-100) };

#endif
