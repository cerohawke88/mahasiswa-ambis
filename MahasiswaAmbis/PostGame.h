#pragma once
#include <iostream>
#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <stdio.h>
#include <allegro5\allegro_ttf.h>
using namespace std;

class PostGame
{
public:
	PostGame();
	~PostGame();
	void showPost();
private:
	ALLEGRO_BITMAP * background;
	ALLEGRO_FONT * font;
};

