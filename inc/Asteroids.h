#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;

#include "Rock.h"
#include "Ship.h"
#include "Bullet.h"

class Asteroids {
private:
	static const int WINDOW_X = 1280;
	static const int WINDOW_Y = 1000;

	static const int FULL_LIVES = 4;
	int lives;

	int level;
	static const int NUM_LEVELS = 5;

	Ship ship;
	vector<Rock> rocks;
	vector<Bullet> bullets;

	Font myFont;

	void drawBullets();
	void drawRocks();
	void drawShip();
	void drawLives();
	void updateRocks();
	void updateShip();
	void updateBullets();
	void splitRock(int index);

public:
	Asteroids();

	void playGame();
	void showMenu();
	void startLevel(int level);
	void update();
	void draw();
	void checkEvent();
	void applyEvents();
	void setFPS(int FPS);
	bool isOpen() const ;

	bool upPressed;
	bool leftPressed;
	bool rightPressed;

	RenderWindow* window;
};
