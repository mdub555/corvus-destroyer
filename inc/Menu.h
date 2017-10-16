#ifndef _MENU_H_
#define _MENU_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <Button.h>

class Menu {
private:
   sf::Text label;
   sf::FloatRect labelBound;
   std::vector<Button*> buttons;

   const int SPACING = 10;
   int totalHeight;

   virtual void createMenu() = 0;

protected:
   void calculateTotalHeight();
   void arrangeButtons();

public:
   Menu();

   void setLabel(const std::string label);
   void setFont(sf::Font &font);

   void addButton(Button *button);
   void draw(sf::RenderWindow* window);

};

#endif
