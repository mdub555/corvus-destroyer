/* Ship class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include "Object.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Ship : public Object {
private:
	static constexpr double PI = 3.14159265;

	static const int HEIGHT = 20;
	static const int WIDTH = 15;

	static const int ROTATION_SPEED = 6;
	int rotation;
	static constexpr double ACCELERATION = 1;
	bool accel;

	static const int WINDOW_X = 1280;
	static const int WINDOW_Y = 1000;

	void createShape();
	void accelerate();

public:
	Ship();

	double getHeight() const ;
	double getWidth() const ;

	void update();
	void startAccel();
	void stopAccel();
	void setRotate(int direction);
	void move(double x, double y);
};
