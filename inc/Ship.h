/* Ship class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Ship {
private:
	int height;
	int width;

	int yPos;
	int xPos;

	static const int WINDOW_X = 1280;
	static const int WINDOW_Y = 1000;

	void createShape();

public:
	Ship();

	RectangleShape center;
	CircleShape left;
	CircleShape right;

	double getYPos() const ;
	double getXPos() const ;
	double getHeight() const ;
	double getWidth() const ;

	void move(double x, double y);

	void draw(RenderWindow* window) const ;
};
