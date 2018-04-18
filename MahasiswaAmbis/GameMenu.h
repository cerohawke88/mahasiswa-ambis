#pragma once
#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>pg
#include <stdio.h>
#include <allegro5\allegro_ttf.h>
#include "PostGame.h"

class GameMenu
{
public:
	typedef struct
	{
		ALLEGRO_COLOR menu;
		ALLEGRO_COLOR enter;
	}COLOURS;

	COLOURS color;
	PostGame *pg = new PostGame;

	GameMenu();
	~GameMenu();

	bool main_menu(bool& menu, ALLEGRO_EVENT_QUEUE *queue, bool stop, bool gameover);

private:
	ALLEGRO_BITMAP * background;
	ALLEGRO_FONT * font;
	int cekmenu;
	bool resume;
};


