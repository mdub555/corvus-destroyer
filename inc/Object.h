#ifndef OBJECT_H
#define OBJECT_H

#include "Constants.h"
#include "Object.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Object : public Shape {
private:
	Vector2f m_velocity;
	Vector2f m_acceleration;

	void checkGodMode();
	void checkBounds();

	static const int flashDuration = 125;

protected:
	Color outlineColor;
	Color fillColor;

	bool inGodMode = false;
	int godModeDuration = 0;
	Clock godModeTimer;

public:
	Object();

	void setVelocity(const Vector2f&);
	void setAcceleration(const Vector2f&);

	Vector2f getVelocity() const ;
	Vector2f getAcceleration() const ;

	void update();
	void draw(RenderWindow* window);

	void godMode(int);
	bool isInGodMode() const ;
	void flash();
};

#endif
