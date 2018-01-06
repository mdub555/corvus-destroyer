/* Bullet class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#ifndef _BULLET_H_
#define _BULLET_H_

#include "Object.h"
#include "Rock.h"

#include <SFML/Graphics.hpp>

class Bullet : public Object {
private:
	sf::Vector2f m_size;
	static constexpr double WIDTH = 10;
	static constexpr double HEIGHT = 2;
	static constexpr double BULLET_SPEED = 1500/FRAMERATE;

	sf::Clock clock;

public:
	Bullet(const sf::Vector2f& position = sf::Vector2f(0, 0));
	void setSize(const sf::Vector2f& size);
	const sf::Vector2f& getSize() const;
	virtual std::size_t getPointCount() const override;
	virtual sf::Vector2f getPoint(std::size_t index) const override;

	void addVelocity(const sf::Vector2f&);

	void setRotation(float);
	bool hit(const Rock&) const ;
	int timeAlive() const ;
};

#endif
