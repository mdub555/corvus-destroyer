#include "PauseMenu.h"
#include "Button.h"

PauseMenu::PauseMenu() {
   createMenu();
}

void PauseMenu::createMenu() {
   setLabel("PAUSE");
   addButton(new Button("resume"));
   buttons[0]->setAction(MenuAction::POP);
   addButton(new Button("exit"));
   buttons[1]->setAction(MenuAction::EXIT);
   arrangeButtons();
}

MenuAction PauseMenu::select() const {
   return buttons[currentButton]->getAction();
}
