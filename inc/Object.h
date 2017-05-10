#pragma once

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Object {
private:
	static const int MAX_VELOCITY = 50;

	double xPos;
	double yPos;
	double xVel;
	double yVel;
	double xAcc;
	double yAcc;

	static const int WINDOW_X = 1280;
	static const int WINDOW_Y = 1000;

	void updatePosition();

protected:
	Shape* shape;

public:
	Object();

	void setPos(double, double);
	void setXPos(double);
	void setYPos(double);
	void setXVel(double);
	void setYVel(double);
	void setXAcc(double);
	void setYAcc(double);

	double getXPos() const ;
	double getYPos() const ;
	double getXVel() const ;
	double getYVel() const ;
	double getXAcc() const ;
	double getYAcc() const ;

	void update();
	void draw(RenderWindow* window);

};
