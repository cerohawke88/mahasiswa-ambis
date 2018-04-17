#pragma once
#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

class InputManager
{
private:
	ALLEGRO_KEYBOARD_STATE keyState;
public:
	InputManager();
	~InputManager();

	void update();

	bool isKeyPressed(ALLEGRO_EVENT event, int key);
	bool isKeyDown(int key);
	bool isKeyReleased(ALLEGRO_EVENT event, int key);
};

