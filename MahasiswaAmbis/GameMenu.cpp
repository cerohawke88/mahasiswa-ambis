#include "stdafx.h"
#include "GameMenu.h"




GameMenu::GameMenu()
{
	background = al_load_bitmap("map.png");
	GameMenu::cekmenu = 0;
}


GameMenu::~GameMenu()
{

}


void GameMenu::main_menu(bool &menu, ALLEGRO_EVENT_QUEUE *queue, bool& stop, bool& gameover)
{
	color.menu = al_map_rgb(122, 113, 143);
	font = al_load_font("font.ttf", 50, 0);
	color.enter = al_map_rgb(0, 0, 0);
	while (menu)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);
		al_draw_bitmap(GameMenu::background, 0, 0, NULL);
		if (!stop)
		{
			if (gameover) {
				al_draw_text(font, color.menu, 450, ScreenHeight / 2 - 110, ALLEGRO_ALIGN_CENTRE, "Game Over");
			}
			else {
				if (cekmenu == 0) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 110, ALLEGRO_ALIGN_CENTRE, "Start");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 110, ALLEGRO_ALIGN_CENTRE, "Start");
				}
				if (cekmenu == 1) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 40, ALLEGRO_ALIGN_CENTRE, "Credits");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 40, ALLEGRO_ALIGN_CENTRE, "Credits");
				}

				if (cekmenu == 2) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 + 30, ALLEGRO_ALIGN_CENTRE, "Exit");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 30, ALLEGRO_ALIGN_CENTRE, "Exit");
				}
			}

		}
		else if (stop)
		{
			if (cekmenu == 0) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 170, ALLEGRO_ALIGN_CENTRE, "New Game");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 170, ALLEGRO_ALIGN_CENTRE, "New Game");
			}
			if (cekmenu == 1) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 100, ALLEGRO_ALIGN_CENTRE, "Resume Game");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 100, ALLEGRO_ALIGN_CENTRE, "Resume Game");
			}
			if (cekmenu == 2) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 30, ALLEGRO_ALIGN_CENTRE, "Credits");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 30, ALLEGRO_ALIGN_CENTRE, "Credits");
			}
			if (cekmenu == 3) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 + 40, ALLEGRO_ALIGN_CENTRE, "Exit");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 40, ALLEGRO_ALIGN_CENTRE, "Exit");
			}




		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ENTER:
				stop = false;
				menu = true;
				if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
				{
					if (cekmenu == 0) {
						stop = false;
						menu = false;
					}
					else if (cekmenu == 1) {
						stop = true;
						menu = false;
					}
				}
				break;
			case ALLEGRO_KEY_DOWN:
				cekmenu++;
				if (stop) {
					if (cekmenu == 4) {
						cekmenu = 0;
					}
				}
				else {
					if (cekmenu == 3) {
						cekmenu = 0;
					}
				}
				cout << cekmenu << endl;
				break;
			case ALLEGRO_KEY_UP:
				cekmenu--;
				if (stop) {
					if (cekmenu == -1) {
						cekmenu = 3;
					}
				}
				else {
					if (cekmenu == -1) {
						cekmenu = 2;
					}
				}
				cout << cekmenu << endl;
				break;
			}
		}
		al_flip_display();
	}
}