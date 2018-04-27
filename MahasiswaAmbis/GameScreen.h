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
	void draw(int level);
	void eventkey(ALLEGRO_EVENT events);
	void init();
	void showKoin(int x, int width, MahasiswaAmbis* ma);
	void drawTooltip(int x, int y);
	void drawTooltip2(int x, int y);
	void drawTooltip3(int x, int y);
	void drawTooltip4(int x, int y);
	void drawTooltip5(int x, int y);
	void drawAllObject(vector<MahasiswaMusuh*> *musuh, vector<Gorengan*> *gr, vector<Kucing*> *kucing, vector<Buku*> *buku, vector<Koin*> *koin, int& level);

private:
	ALLEGRO_BITMAP *background1;
	ALLEGRO_BITMAP *background2;
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
	ALGIF_ANIMATION *gif_life;
	ALLEGRO_BITMAP *tooltip;
	ALLEGRO_BITMAP *tooltip2;
	ALLEGRO_BITMAP *tooltip3;
	ALLEGRO_BITMAP *tooltip4;
	ALLEGRO_BITMAP *tooltip5;

	const float FPS = 60.0;
	const float frameFPS = 15.0;
};

