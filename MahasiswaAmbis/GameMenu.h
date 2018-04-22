#pragma once
#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <stdio.h>
#include <allegro5\allegro_ttf.h>
#include "algif.h"
#include "MahasiswaAmbis.h"
#include "SoundManager.h"
#include "Saveload.h"

class GameMenu
{
public:
	typedef struct
	{
		ALLEGRO_COLOR menu;
		ALLEGRO_COLOR enter;
		ALLEGRO_COLOR white;
	}COLOURS;

	COLOURS color, black;

	GameMenu();
	~GameMenu();

	void main_menu(bool& menu, ALLEGRO_EVENT_QUEUE *queue, int& returnmenu, int validasi, MahasiswaAmbis* ma, SoundManager* sound);
	void post_game(bool& menu);

private:
	ALLEGRO_BITMAP * background_post;
	ALLEGRO_BITMAP * background_menu;
	ALLEGRO_BITMAP * background_gameover;
	ALLEGRO_FONT * font;
	ALGIF_ANIMATION *coin, *life, *book, *life150;
	MahasiswaAmbis *ma;
	int cekmenu;
	bool resume;
	Saveload *sl;
};


