#include "PauseMenu.h"
#include "Button.h"

PauseMenu::PauseMenu() {
   createMenu();
}

void PauseMenu::createMenu() {
   setLabel("PAUSE");
   addButton(new Button("resume"));
   addButton(new Button("exit"));
   arrangeButtons();
}
