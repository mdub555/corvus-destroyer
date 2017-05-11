/* Ship class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include "Constants.h"
#include "Object.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Ship : public Object {
private:
	static const int HEIGHT = 20;
	static const int WIDTH = 15;

	static constexpr double MAX_VELOCITY = 1800.0/FRAMERATE;
	static constexpr double ROTATION_SPEED = 180.0/FRAMERATE;
	int rotation;
	static constexpr double ACCELERATION = 30.0/FRAMERATE;
	bool accel;

	void createShape();
	void accelerate();

public:
	Ship();

	double getHeight() const ;
	double getWidth() const ;

	void update();
	void startAccel();
	void stopAccel();
	void setRotate(int);
	void validateSpeed();
};
