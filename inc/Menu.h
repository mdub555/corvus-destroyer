#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
#include <Button.h>
using namespace sf;

class Menu {
private:
  string label;
  vector<Button> buttons;

  virtual void createMenu();

public:
  Menu();

  void setLabel(const string label);

  void addButton(Button button);
  void organizeButtons();
  void draw(RenderWindow* window);

};

#endif
