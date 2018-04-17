#pragma once

#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include "GameScreen.h"
#include "MahasiswaAmbis.h"

class GameInit
{
public:
	GameInit();
	~GameInit();

	void init();
	void setDisplay();
	bool getDraw();
	void setDraw(bool);
	bool getDone();
	void run();
private:

	const float FPS = 60.0;
	const float frameFPS = 15.0;
	int ceklompat = 0;
	float cameraPosition[2] = { 0,0 };

	ALLEGRO_KEYBOARD_STATE keyState;

	ALLEGRO_TRANSFORM camera;

	ALLEGRO_TIMER *timer;
	ALLEGRO_TIMER *frameTimer;

	ALLEGRO_EVENT_QUEUE *event_queue;

	ALLEGRO_DISPLAY *display;

	GameScreen *gs;
	MahasiswaAmbis *ma;

	bool draw = true;
	bool done = false, active = false;
};

