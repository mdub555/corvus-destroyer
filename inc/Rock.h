/* Rock class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#ifndef _ROCK_H_
#define _ROCK_H_

#include "Util.h"
#include "Object.h"
#include "Ship.h"
#include <vector>

#include <SFML/Graphics.hpp>

class Rock : public Object {
private:
	static const unsigned int NUM_POINTS = 16;
	static const unsigned int NUM_SPLIT_ROCKS = 3;
	int    level;
	double radius;
	double speed;

	std::vector<sf::Vector2f> m_points;

	void createShape();

public:
	Rock(int);
	Rock(int, Rock&);
	virtual unsigned int getPointCount() const override;
	virtual sf::Vector2f getPoint(unsigned int index) const override;

	bool checkShipCollision(const Ship&);
	int getRadius() const ;

	std::vector<Rock> split();
};

#endif
