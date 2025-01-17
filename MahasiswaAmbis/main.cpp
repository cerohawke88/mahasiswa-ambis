// MahasiswaAmbisOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <allegro5\allegro5.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "MahasiswaAmbis.h"
#include "MahasiswaMusuh.h"
#include "GameScreen.h"
#include "GameMenu.h"
#include "Gorengan.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Koin.h"
#include "Buku.h"
#include "Kucing.h"
#include "Saveload.h"
#include "GameSet.h"
#include "Boss.h"

int main()
{
	ALLEGRO_DISPLAY *display;
	const float FPS = 60.0;
	const float frameFPS = 15.0;
	ALLEGRO_FONT *font;

	//=============Init allegro===================
	font = al_load_font("font.ttf", 50, 0);
	if (!al_init()) {
		al_show_native_message_box(NULL, "ERROR", NULL, "COULD NOT install allegro", NULL, NULL);
	}
	display = al_create_display(ScreenWidth, ScreenHeight);
	if (!display) {
		al_show_native_message_box(NULL, "ERROR", NULL, "COULD NOT SHOW DISPLAY", NULL, NULL);
	}
	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}
	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	al_set_window_position(display, 200, 200);

	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	//=============Init allegro===================


	//===================deklrasi================================
	InputManager input;
	GameSet GameSet;
	bool menu = true;
	SoundManager* sound = new SoundManager();

	int done, draw, active;
	float cameraPosition[2] = { 0,0 };
	bool gameover, stop;  
	int xcu, validasi_menu, returnmenu, level;
	//===================deklrasi================================


	//===============set semua object=============================
	int perulangan;
	vector<Gorengan*> gr;
	vector<MahasiswaMusuh*> musuh;
	vector<Boss* > boss;
	vector<Koin*> koin;
	vector<Buku*> buku;
	vector<Kucing*> kucing;

			//===============clear vector saat game over=====================
			gr.clear();
			musuh.clear();
			koin.clear();
			buku.clear();
			kucing.clear();
			boss.clear();
			//===============clear vector saat game over=====================

	for (perulangan = 0; perulangan < 2; perulangan++) {
		gr.push_back(new Gorengan);
	}
	for (perulangan = 0; perulangan < 2; perulangan++) {
		musuh.push_back(new MahasiswaMusuh);
	}
	for (perulangan = 0; perulangan < 4; perulangan++) {
		koin.push_back(new Koin);
	}
	for (perulangan = 0; perulangan < 15; perulangan++) {
		buku.push_back(new Buku);
	}
	for (perulangan = 0; perulangan < 5; perulangan++) {
		kucing.push_back(new Kucing);
	}
	boss.push_back(new Boss(2500));
	boss.push_back(new Boss(2700));
	//===============set semua object=============================


	//=============init camera dan display===============
	ALLEGRO_TRANSFORM camera;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_TIMER *frameTimer = al_create_timer(1.0 / frameFPS);
	//=============init camera dan display===============

	//========================queue pada event=============
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//========================queue pada event=============

	al_start_timer(timer);
	al_start_timer(frameTimer);

	GameMenu *gm = new GameMenu();
	Saveload *sl = new Saveload();
	GameScreen *gs = new GameScreen();
	MahasiswaAmbis *ma = new MahasiswaAmbis();
	menu = true;
	level = 1;


menustart:

	//======set after Game Over==========
	ma->afterGO();
	GameSet.setValidasiTrue(&musuh, &gr, &kucing, &buku, &koin, &boss);
	//======set after Game Over==========


	//=============Set variable================
	done = 0; draw = true; active = false;
	gameover = false; stop = false;
	xcu = 0, validasi_menu = 0; //0: menu biasa, 1: resume, 2: gameover
	returnmenu = 1;
	//=============Set variable================
	
	al_start_timer(timer);
	while (!done && returnmenu == 1) {
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		input.update(); 
		//cout << ma->getX() << " " << ma->getY() << endl;

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = 1;
		}

		else if (events.type == ALLEGRO_EVENT_TIMER) {
			if (ma->getY() > 500) {
				xcu = 0;
				menu = true; validasi_menu = 2;
				ma->setX(10); ma->setY(10);
				level = 1;
			}
			else if (ma->getX() > 3900 && level == 1) {
				sl->Save(ma->highscore());
				xcu = 0;
				menu = true; validasi_menu = 4;
				ma->setX(10); ma->setY(10);
				level++;
				GameSet.setValidasiTrue(&musuh, &gr, &kucing, &buku, &koin, &boss);
			}
			else if (ma->getX() > 2895 && level == 2) {
				sl->Save(ma->highscore());
				xcu = 0;
				menu = true; validasi_menu = 4;
				ma->setX(10); ma->setY(10);
				level++;
				GameSet.setValidasiTrue(&musuh, &gr, &kucing, &buku, &koin, &boss);
			}
			else {
				xcu = ma->getX();
				ma->cekLompat(&musuh, menu, validasi_menu, xcu, level, &boss);

				if (events.timer.source == timer) {
					active = true;
					if (input.isKeyDown(ALLEGRO_KEY_UP) && ma->getJump()) {
						ma->lompat();
						sound->playJump();
					}

					if (input.isKeyDown(ALLEGRO_KEY_SPACE) && ma->getJump()) {
						ma->doubleJump();
						sound->playJump();
						sound->stopGameover();
					}
					else if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
						ma->maju(&musuh, menu, validasi_menu, xcu, level);
					}
					else if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
						if (ma->getX() >= 10) {
							ma->mundur(&musuh, menu, validasi_menu, xcu, level);
						}
						if (ma->getX() < 10) {
							ma->setX(10);
						}
					}
					else if (input.isKeyDown(ALLEGRO_KEY_ESCAPE)) {
						validasi_menu = 1;
						menu = true;
						xcu = 0;
					}
					else {
						ma->getVel();
						active = false;
					}

					//===collision=============
					ma->cekGorengan(&gr, level);
					ma->cekBuku(&buku, level);
					ma->cekKoin(&koin, level);
					ma->cekKucing(&kucing, menu, validasi_menu, xcu, level);

					cout << ma->getX() << "	" << ma->getY() << endl;

					//===SCORETOTAL (IPK)=============
					ma->totalScore1(15.0);
					//cout << "total Score" << ma->getTotalscore1() << endl;

				}
				else if (events.timer.source == frameTimer) {
					if (active) {
						ma->addSourceX(64);
					}
					else {
						ma->setSourceX(64);
					}
					if (ma->getSourceX() >= ma->getWidth()) {
						ma->setSourceX(0);
					}
				}
			}
			gs->CameraUpdate(cameraPosition, xcu, 0, 64, 0, level);
			
			al_identity_transform(&camera);
			al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
			al_use_transform(&camera);

			gm->main_menu(menu, event_queue, returnmenu, validasi_menu, ma, sound, level);
			draw = true;
		}

		if (draw) {
			gs->draw(level);
			gs->showKoin(ma->getX(), 64,ma, level);

			//==============show object============================
			gs->drawAllObject(&musuh, &gr, &kucing, &buku, &koin, level, &boss);
			//if (level == 1) {
			//	//boss->draw(0, 0);
			//}
			//==============show object============================

			if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
				ma->drawReg(1);
			}
			else {
				ma->drawReg(0);
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	if (returnmenu == 0) {
		level = 1;
		goto menustart;
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(frameTimer);
	al_destroy_event_queue(event_queue);
}

