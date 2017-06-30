/* Bullet class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "Rock.h"

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet : public Object {
private:
	Vector2f m_size;
	static constexpr double WIDTH = 10;
	static constexpr double HEIGHT = 2;
	static constexpr double BULLET_SPEED = 1500/FRAMERATE;

	Clock clock;

public:
	Bullet(const Vector2f& position = Vector2f(0, 0));
	void setSize(const Vector2f& size);
	const Vector2f& getSize() const;
	virtual std::size_t getPointCount() const;
	virtual Vector2f getPoint(std::size_t index) const;

	void addVelocity(const Vector2f&);

	void setRotation(float);
	bool hit(const Rock&) const ;
	int timeAlive() const ;
};

#endif
