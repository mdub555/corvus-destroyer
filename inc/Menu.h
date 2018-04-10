#ifndef _MENU_H_
#define _MENU_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <Button.h>

class Menu {
private:
   sf::Text label;
   sf::FloatRect labelBound;

   static const int SPACING = 10;
   int totalHeight;

   virtual void createMenu() = 0;
   void getLabelBound();

   sf::Clock clock;
   const sf::Time changeDelay = sf::milliseconds(150);

protected:
   std::size_t currentButton = 0;
   std::vector<Button*> buttons;
   void calculateTotalHeight();
   void arrangeButtons();

public:
   Menu();

   void setLabel(const std::string label);
   void setFont(sf::Font &font);

   void addButton(Button *button);
   void draw(sf::RenderWindow* window);

   void navigateUp();
   void navigateDown();
   virtual MenuAction select() const = 0;
};

#endif
