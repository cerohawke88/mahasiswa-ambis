#pragma once

#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>


class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	void CameraUpdate(float *cameraPosition, float x, float y, int widht, int height);
	void draw();
	void eventkey(ALLEGRO_EVENT events);
	void init();
	
private:
	ALLEGRO_BITMAP *background;
	ALLEGRO_DISPLAY *display;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_TRANSFORM camera;
	ALLEGRO_TIMER *timer;
	ALLEGRO_TIMER *frameTimer;
	ALLEGRO_EVENT_QUEUE *event_queue;

	const float FPS = 60.0;
	const float frameFPS = 15.0;
};

