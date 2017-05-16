#pragma once

#include "Constants.h"
#include "Object.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Object {
private:
	double xPos;
	double yPos;
	double xVel;
	double yVel;
	double xAcc;
	double yAcc;

	void checkGodMode();

	static const int flashDuration = 125;

protected:
	Shape* shape;
	Shape* hitbox;
	vector<Shape*> hitboxes;
	bool inGodMode;
	int godModeDuration = 0;
	Clock godModeTimer;

public:
	Object();

	void setPos(double, double);
	void setPos(Vector2f);
	void setXPos(double);
	void setYPos(double);
	void setVel(double, double);
	void setXVel(double);
	void setYVel(double);
	void setAcc(double, double);
	void setXAcc(double);
	void setYAcc(double);
	void setRotation(double);

	double getXPos() const ;
	double getYPos() const ;
	double getXVel() const ;
	double getYVel() const ;
	double getXAcc() const ;
	double getYAcc() const ;
	double getRotation() const ;

	void update();
	void updatePosition();
	void draw(RenderWindow* window);

	void godMode(int);
	bool isInGodMode() const ;
	void flash();
};
