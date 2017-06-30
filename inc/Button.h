#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Button : public RectangleShape {
private:
  Text label;

public:
  Button();
  Button(const Vector2f& size);

  void setLabel(const string label);
  void setLabelColor(const Color labelColor);

  bool pressed(Event event);
  void draw(RenderWindow* window);
};

#endif
