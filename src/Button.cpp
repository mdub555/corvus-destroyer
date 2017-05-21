#include "Button.h"

Button::Button() : Button(Vector2f(10, 10)) {}

Button::Button(const Vector2f& size) {
	setSize(size);
	setOrigin(Vector2f(size.x/2, size.y/2));
}

void Button::setLabel(const string string) {
	label.setString(string);
	return;
}

void Button::setLabelColor(const Color color) {
	label.setColor(color);
	return;
}

bool Button::pressed(Event event) {
	Vector2f pressLocation = Vector2f(event.mouseButton.x, event.mouseButton.y);
	if (getGlobalBounds().contains(pressLocation)) return true;
	return false;
}

void Button::draw(RenderWindow* window) {
	// draw button
	window->draw(*this);

	// center text
	FloatRect textRect = label.getLocalBounds();
	label.setOrigin(textRect.left + textRect.width/2.0f,
					textRect.top  + textRect.height/2.0f);
	label.setPosition(getOrigin());

	// draw text
	window->draw(label);
	return;
}
