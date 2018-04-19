#include "stdafx.h"
#include "PostGame.h"


PostGame::PostGame()
{
	background = al_load_bitmap("map.png");
	life = algif_load_animation("life.gif");
	coin = algif_load_animation("coins.gif");
	book = algif_load_animation("Books.gif");

}


PostGame::~PostGame()
{
}

void PostGame::post_game(bool& menu)
{
	color.post = al_map_rgb(122, 113, 143);
	black.post = al_map_rgb(0, 0, 0);
	font = al_load_font("font.ttf", 60, 0);
	al_draw_bitmap(background, 0, 0, NULL);


	while (menu)
	{
		al_draw_text(font, black.post, ScreenWidth / 2, ScreenHeight / 2 - 200, ALLEGRO_ALIGN_CENTRE, "STAGE COMPLETED!");

		//al_draw_text(font, color.post, ScreenWidth / 3, ScreenHeight / 2 - 110, ALLEGRO_ALIGN_CENTRE, "COINS");
		al_draw_bitmap(algif_get_bitmap(coin, al_get_time()), 170, 85, NULL);
		//al_draw_text(font, color.post, ScreenWidth / 3, ScreenHeight / 2 - 40, ALLEGRO_ALIGN_CENTRE, "LIVES");
		//al_draw_bitmap_region(life, 50, 0 * al_get_bitmap_height(life) / 2, 64, 64, 380, 10, NULL);
		al_draw_bitmap(algif_get_bitmap(life, al_get_time()), 170, 168, NULL);
		//al_draw_text(font, color.post, ScreenWidth / 3, ScreenHeight / 2 + 30, ALLEGRO_ALIGN_CENTRE, "SCORE");
		al_draw_bitmap(algif_get_bitmap(book, al_get_time()), 170, 225, NULL);

		al_flip_display();
	}
}
