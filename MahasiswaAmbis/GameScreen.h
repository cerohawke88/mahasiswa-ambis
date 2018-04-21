#pragma once

#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "algif.h"
#include "MahasiswaAmbis.h"


class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	typedef struct
	{
		ALLEGRO_COLOR menu;
		ALLEGRO_COLOR enter;
		ALLEGRO_COLOR white;
	}COLOURS;

	COLOURS color;

	void CameraUpdate(float *cameraPosition, float x, float y, int widht, int height);
	void draw();
	void eventkey(ALLEGRO_EVENT events);
	void init();
	void showKoin(int x, int width, MahasiswaAmbis* ma);
	
private:
	ALLEGRO_BITMAP *background;
	ALLEGRO_DISPLAY *display;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_TRANSFORM camera;
	ALLEGRO_TIMER *timer;
	ALLEGRO_TIMER *frameTimer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_FONT * font;
	ALGIF_ANIMATION *gif_koin;
	ALGIF_ANIMATION *gif_buku;
	ALGIF_ANIMATION *gif_gorengan;

	const float FPS = 60.0;
	const float frameFPS = 15.0;
};

