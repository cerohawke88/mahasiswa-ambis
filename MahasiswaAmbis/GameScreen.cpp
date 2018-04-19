#include "stdafx.h"
#include "GameScreen.h"

GameScreen::GameScreen()
{
	background = al_load_bitmap("mapp.png");
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