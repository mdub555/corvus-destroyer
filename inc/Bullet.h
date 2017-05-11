/* Bullet class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include "Rock.h"

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet : public Object {
private:
	static constexpr double WIDTH = 10;
	static constexpr double HEIGHT = 2;
	static constexpr double BULLET_SPEED = 2500/FRAMERATE;

	void createShape();

public:
	Bullet();

	void setRotation(double);
	bool hit(const Rock&) const ;
};
