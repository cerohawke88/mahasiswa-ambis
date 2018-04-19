#pragma once

#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <stdio.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_ttf.h>
#include "algif.h"

class PostGame
{
public:
	typedef struct {
		ALLEGRO_COLOR post;
	}COLOURS;

	COLOURS color, black;
	PostGame();
	~PostGame();

	void post_game(bool& menu, ALLEGRO_EVENT_QUEUE *queue);
private:
	ALLEGRO_BITMAP * background, *life;
	ALLEGRO_FONT * font;
	ALGIF_ANIMATION *coin;


};

