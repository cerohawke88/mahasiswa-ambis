#include "stdafx.h"
#include "GameScreen.h"

GameScreen::GameScreen()
{
	background = al_load_bitmap("mapp.png");
	font = al_load_font("font.ttf", 20, 0);
	al_init_ttf_addon();
	color.menu = al_map_rgb(122, 113, 143);
	color.enter = al_map_rgb(0, 0, 0);
	color.white = al_map_rgb(255, 255, 255);
	gif_koin = algif_load_animation("Coin.gif");
	gif_gorengan = algif_load_animation("Gor.gif");
	gif_buku = algif_load_animation("Book.gif");
}


GameScreen::~GameScreen()
{
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(frameTimer);
	al_destroy_event_queue(event_queue);
}

void GameScreen::init()
{
	al_install_keyboard();
}

void GameScreen::showKoin(int x, int width)
{
	int xx;
	xx = -(ScreenWidth / 2) + (x + 300 / 2);

	if (xx < 100) {
		xx = 100;
	}

	al_draw_bitmap(algif_get_bitmap(gif_koin, al_get_time()), xx - 60, 5, NULL);
	al_draw_text(font, color.enter, xx, 30, ALLEGRO_ALIGN_CENTRE, "10");

	al_draw_bitmap(algif_get_bitmap(gif_buku, al_get_time()), xx + 30, 5, NULL);
	al_draw_text(font, color.enter, xx + 90, 30, ALLEGRO_ALIGN_CENTRE, "5");

	al_draw_bitmap(algif_get_bitmap(gif_gorengan, al_get_time()), xx + 120, 20, NULL);
	al_draw_text(font, color.enter, xx + 170, 30, ALLEGRO_ALIGN_CENTRE, "3");
}

void GameScreen::CameraUpdate(float *cameraPosition, float x, float y, int widht, int height)
{
	cameraPosition[0] = -(ScreenWidth / 2) + (x + widht / 2);
	cameraPosition[1] = -(ScreenHeight / 2) + (y + height / 2);

	if (cameraPosition[0] < 0) {
		cameraPosition[0] = 0;
	}
	if (cameraPosition[1] < 0) {
		cameraPosition[1] = 0;
	}
}

void GameScreen::draw()
{
	al_draw_bitmap(GameScreen::background, 0, 0, NULL);
}


void GameScreen::eventkey(ALLEGRO_EVENT events)
{
	al_wait_for_event(event_queue, &events);
}