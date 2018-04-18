#include "PostGame.h"
#include "stdafx.h"



PostGame::PostGame()
{
	background = al_load_bitmap("map.png");
}

void PostGame::showPost()
{
	//al_draw_text(font, al_map_rgb(122, 113, 143), ScreenWidth / 2, ScreenHeight / 2 - 110, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
	al_draw_bitmap(PostGame::background, 0, 0, NULL);
}


PostGame::~PostGame()
{
}
