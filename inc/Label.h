#ifndef _LABEL_H_
#define _LABEL_H_

#include <SFML/Graphics.hpp>

class Label : public sf::Text {
private:
   bool timed;
   sf::Clock clock;
   int duration;

public:
   Label(sf::String text, sf::Vector2f position, int duration);

   void update();

   bool durationFinished() const;
};

#endif
