#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "util/constants.h"

#include <SFML/Graphics.hpp>

class Object : public sf::Shape {
private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;

	void checkGodMode();
	void checkBounds();

	static const int flashDuration = 125;

protected:
	sf::Color outlineColor;
	sf::Color fillColor;

	bool inGodMode = false;
	int godModeDuration = 0;
	sf::Clock godModeTimer;

public:
	Object();

	void setVelocity(const sf::Vector2f&);
	void setAcceleration(const sf::Vector2f&);

	sf::Vector2f getVelocity() const ;
	sf::Vector2f getAcceleration() const ;

	void update();
	void draw(sf::RenderWindow* window);

	void godMode(int);
	bool isInGodMode() const ;
	void flash();
};

#endif
