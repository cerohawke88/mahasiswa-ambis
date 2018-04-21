#include "stdafx.h"
#include "GameMenu.h"

GameMenu::GameMenu()
{
	background_gameover = al_load_bitmap("GameOver.png");
	background_menu = al_load_bitmap("main_menu.png");
	GameMenu::cekmenu = 0;
	resume = false;
	font = al_load_font("font.ttf", 50, 0);
	al_init_ttf_addon();
	color.menu = al_map_rgb(122, 113, 143);
	color.enter = al_map_rgb(0, 0, 0);
	color.white = al_map_rgb(255, 255, 255);

	background_post = al_load_bitmap("map.png");
	life = algif_load_animation("life.gif");
	coin = algif_load_animation("coins.gif");
	book = algif_load_animation("Books.gif");
}


GameMenu::~GameMenu()
{

}


void GameMenu::main_menu(bool &menu, ALLEGRO_EVENT_QUEUE *queue, int& returnmenu, int validasi)
{
	int bekasgameover = 0;
	
	while (menu)
	{
		//cout << "menu : " << menu;
		ALLEGRO_EVENT ev;

		al_wait_for_event(queue, &ev);
		if (validasi==2) { //gameover
			al_draw_bitmap(GameMenu::background_gameover, 0, 0, NULL);
			al_draw_text(font, color.white, ScreenWidth / 2, ScreenHeight / 2 - 50, ALLEGRO_ALIGN_CENTRE, "Game Over");
		}
		else if (validasi == 4) {
			al_draw_bitmap(GameMenu::background_post, 0, 0, NULL);
		}
		else {
			al_draw_bitmap(GameMenu::background_menu, 0, 0, NULL);
		}

		if (validasi==0) //menu awal
		{
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
		else if (validasi == 1) //resume
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
		else if (validasi == 3)  //credits
		{
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 170, ALLEGRO_ALIGN_CENTRE, "This game created by: ");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 100, ALLEGRO_ALIGN_CENTRE, "1. Megandi");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 - 30, ALLEGRO_ALIGN_CENTRE, "2. Arab si tampan");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 40, ALLEGRO_ALIGN_CENTRE, "3. Cleo");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 110, ALLEGRO_ALIGN_CENTRE, "4. Vicky");
			al_draw_text(font, color.menu, ScreenWidth / 2, ScreenHeight / 2 + 180, ALLEGRO_ALIGN_CENTRE, "5. Daffa putra zeus");
		}

		else if (validasi == 4)  //post game
		{
			al_draw_text(font, color.enter, ScreenWidth / 2, ScreenHeight / 2 - 200, ALLEGRO_ALIGN_CENTRE, "STAGE COMPLETED!");

			//al_draw_text(font, color.post, ScreenWidth / 3, ScreenHeight / 2 - 110, ALLEGRO_ALIGN_CENTRE, "COINS");
			al_draw_bitmap(algif_get_bitmap(coin, al_get_time()), 170, 85, NULL);
			//al_draw_text(font, color.post, ScreenWidth / 3, ScreenHeight / 2 - 40, ALLEGRO_ALIGN_CENTRE, "LIVES");
			//al_draw_bitmap_region(life, 50, 0 * al_get_bitmap_height(life) / 2, 64, 64, 380, 10, NULL);
			al_draw_bitmap(algif_get_bitmap(life, al_get_time()), 170, 168, NULL);
			//al_draw_text(font, color.post, ScreenWidth / 3, ScreenHeight / 2 + 30, ALLEGRO_ALIGN_CENTRE, "SCORE");
			al_draw_bitmap(algif_get_bitmap(book, al_get_time()), 170, 225, NULL);
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ENTER:
				if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
				{
					if (validasi == 2) {
						//gameover
						menu = true;
						validasi = 0;
						bekasgameover = 1;
						//sound->stopGameover();
					}
					else if (validasi == 0) {
						if (cekmenu == 0) {
							//start game
							menu = false;
							if (bekasgameover == 1) {
								returnmenu = 0;
							}
						}
						else if (cekmenu == 1) {
							//highscore
							cout << "highscore" << endl;
						}
						else if (cekmenu == 2) {
							//credit
							validasi = 3;
						}
						else if (cekmenu == 3) {
							//exit game
							cout << "exit game" << endl;
							returnmenu = 3;
							menu = false;
						}
					}
					else if(validasi == 1){
						if (cekmenu == 0) {
							//start game lagi
							cout << "start game" << endl;
							returnmenu = 0;
							menu = false;
						}
						else if (cekmenu == 1) {
							//resume
							menu = false;
							cout << "resume" << endl;
						}
						else if (cekmenu == 2) {
							//exit game
							cout << "exit game" << endl;
							returnmenu = 3;
							menu = false;

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
				if (validasi == 3) {
					validasi = 0;
				}
				else if (validasi == 4) {
					menu = true;
					validasi = 0;
				}
				break;
			}
		}
		al_flip_display();
	}
}

void GameMenu::post_game(bool& menu)
{
}
