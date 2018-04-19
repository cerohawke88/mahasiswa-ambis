#include "stdafx.h"
#include "GameMenu.h"

GameMenu::GameMenu()
{
	background = al_load_bitmap("map.png");
	life = algif_load_animation("life.gif");
	coin = algif_load_animation("coins.gif");
	book = algif_load_animation("Books.gif");
	GameMenu::cekmenu = 0;
	resume = false;
}


GameMenu::~GameMenu()
{

}


bool GameMenu::main_menu(bool &menu, ALLEGRO_EVENT_QUEUE *queue, bool stop, bool gameover)
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
				
			}
			else{
				al_init_ttf_addon();
				if (!al_init()) //returns a value of -1 if
					return -1;
				if (cekmenu == 0) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 150, ALLEGRO_ALIGN_CENTRE, "Start");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 150, ALLEGRO_ALIGN_CENTRE, "Start");
				}
				if (cekmenu == 1) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 80, ALLEGRO_ALIGN_CENTRE, "Highscore");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 80, ALLEGRO_ALIGN_CENTRE, "Highscore");
				}
				if (cekmenu == 2) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 10, ALLEGRO_ALIGN_CENTRE, "Credits");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 10, ALLEGRO_ALIGN_CENTRE, "Credits");
				}
				if (cekmenu == 3) {
					al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 + 60, ALLEGRO_ALIGN_CENTRE, "Exit");
				}
				else {
					al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 60, ALLEGRO_ALIGN_CENTRE, "Exit");
				}
			}
		

		}
		else if (stop && !resume)
		{
			if (cekmenu == 0) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 170, ALLEGRO_ALIGN_CENTRE, "New Game");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight   / 2 - 170, ALLEGRO_ALIGN_CENTRE, "New Game");
			}
			if (cekmenu == 1) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 100, ALLEGRO_ALIGN_CENTRE, "Resume Game");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 100, ALLEGRO_ALIGN_CENTRE, "Resume Game");
			}
			if (cekmenu == 2) {
				al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 30, ALLEGRO_ALIGN_CENTRE, "Exit");
			}
			else {
				al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 30, ALLEGRO_ALIGN_CENTRE, "Exit");
			}

		}
		else if (stop && resume) 
		{
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 170, ALLEGRO_ALIGN_CENTRE, "This game created by: ");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 100, ALLEGRO_ALIGN_CENTRE, "1. Megandi");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 30, ALLEGRO_ALIGN_CENTRE, "2. Arab si tampan");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 40, ALLEGRO_ALIGN_CENTRE, "3. Cleo");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 110, ALLEGRO_ALIGN_CENTRE, "4. Vicky");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 180, ALLEGRO_ALIGN_CENTRE, "5. Daffa putra zeus");
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ENTER:
				//stop = false;
				//menu = true;
				if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
				{
					if (!stop) {
						if (cekmenu == 0) {
							//start game
							stop = false;
							menu = false;
						}
						else if (cekmenu == 1) {
							//highscore
							stop = false;
							resume = true;
						}
						else if (cekmenu == 2) {
							//credit
							stop = true;
							resume = true;
						}
						else if (cekmenu == 3) {
							//exit game
							return true;
						}
					}
					else if(stop){
						if (cekmenu == 0) {
							//start game lagi
						}
						else if (cekmenu == 1) {
							//resume
							stop = false;
							menu = false;

						}
						else if (cekmenu == 2) {
							//exit game
							return true;

						}
						
					}
					
				}
				break;
			case ALLEGRO_KEY_DOWN:
				cekmenu++;
				if (cekmenu == 4) {
					cekmenu = 0;
				}
				cout << cekmenu << endl;
				break;
			case ALLEGRO_KEY_UP:
				cekmenu--;
				if (cekmenu == -1) {
					cekmenu = 3;
				}
				cout << cekmenu << endl;
				break;
			case ALLEGRO_KEY_ESCAPE:
				if (stop && resume) {
					stop = false;
					resume = false;
				}
				else if (gameover) {
					menu = false;
					cout << "false";
				}
				break;
			}
		}
		al_flip_display();
	}
}

void GameMenu::post_game(bool& menu)
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
