#include "Menu.h"
#include "Util.h"

#include <stdio.h>

Menu::Menu() {
   label.setString("");
}

void Menu::setLabel(const std::string label) {
   this->label.setString(label);
   getLabelBound();
   return;
}

void Menu::getLabelBound() {
   this->labelBound = this->label.getLocalBounds();
   this->label.setOrigin(labelBound.left + labelBound.width/2.0f,
                         labelBound.top  + labelBound.height/2.0f);
}

void Menu::setFont(sf::Font &font) {
   label.setFont(font);
   getLabelBound();
   for (int i = 0; i < (int)buttons.size(); i++) {
      buttons[i]->setFont(font);
   }
}

void Menu::addButton(Button *button) {
   buttons.push_back(button);
   return;
}

void Menu::draw(sf::RenderWindow* window) {
   // draw the title label
   window->draw(label);
   // draw all the buttons
   std::string temp = label.getString();
   for (int i = 0; i < (int)buttons.size(); i++) {
      buttons[i]->draw(window);
   }
   return;
}

void Menu::calculateTotalHeight() {
   totalHeight = 0;

   totalHeight += labelBound.height;
   totalHeight += SPACING; // make title further from buttons
   for (int i = 0; i < (int)buttons.size(); i++) {
      totalHeight += SPACING;
      totalHeight += buttons[i]->getSize().y;
   }
}

void Menu::arrangeButtons() {
   calculateTotalHeight();
   int currentY = (WINDOW_HEIGHT - totalHeight) / 2;
   label.setPosition(WINDOW_WIDTH/2, currentY);// + labelBound.height/2);
   currentY += labelBound.height + SPACING;
   for (int i = 0; i < (int)buttons.size(); i++) {
      currentY += SPACING;
      buttons[i]->Button::setPosition(WINDOW_WIDTH/2, currentY + buttons[i]->getSize().y/2);
      currentY += buttons[i]->getSize().y/2;
   }
}
