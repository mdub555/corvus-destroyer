#include "Menu.h"

Menu::Menu() {
  label = "";
}

void Menu::setLabel(const string label) {
  this->label = label;
  return;
}

void Menu::addButton(Button button) {
  buttons.push_back(button);
  return;
}

void Menu::draw(RenderWindow* window) {
  return;
}

void Menu::organizeButtons() {
  return;
}
