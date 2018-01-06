/* Ship class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#ifndef _SHIP_H_
#define _SHIP_H_

#include "Util.h"
#include "Object.h"

#include <SFML/Graphics.hpp>

class Ship : public Object {
private:
	static const int HEIGHT = 20;
	static const int WIDTH = 15;

	static constexpr double MAX_VELOCITY = 1400.0/FRAMERATE;
	static constexpr double ROTATION_SPEED = 180.0/FRAMERATE;
	int rotation;
	static constexpr double ACCELERATION = 20.0/FRAMERATE;
	bool accel;

	void createShape();
	void accelerate();

public:
	explicit Ship(const sf::Vector2f& position = sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
	virtual std::size_t getPointCount() const override;
	virtual sf::Vector2f getPoint(std::size_t index) const override;

	double getHeight() const ;
	double getWidth() const ;

	void update();
	void startAccel();
	void stopAccel();
	void setRotate(int);
	void validateSpeed();
	void destroyAnimation();
	void respawnInvinsible();
	void respawn();
};

#endif
