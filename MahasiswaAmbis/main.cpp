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

int main()
{
	ALLEGRO_DISPLAY *display;
	const float FPS = 60.0;
	const float frameFPS = 15.0;
	ALLEGRO_FONT *font;


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

	//deklrasi
	InputManager input;
	SoundManager sound;

	bool done = false, draw = true, active = false;
	float cameraPosition[2] = { 0,0 };
	bool gameover = false;
	bool menu = true;
	bool stop = false;

	//===============set semua object=============================
	int perulangan;
	vector<Gorengan*> gr;
	for (perulangan = 0; perulangan < 2; perulangan++) {
		gr.push_back(new Gorengan);
	}

	vector<MahasiswaMusuh*> musuh;
	for (perulangan = 0; perulangan < 2; perulangan++) {
		musuh.push_back(new MahasiswaMusuh);
	}

	vector<Koin*> koin;
	for (perulangan = 0; perulangan < 4; perulangan++) {
		koin.push_back(new Koin);
	}

	vector<Buku*> buku;
	for (perulangan = 0; perulangan < 15; perulangan++) {
		buku.push_back(new Buku);
	}

	vector<Kucing*> kucing;
	for (perulangan = 0; perulangan < 5; perulangan++) {
		kucing.push_back(new Kucing);
	}
	//===============set semua object=============================
	

	//initial
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	

	ALLEGRO_KEYBOARD_STATE keyState;

	ALLEGRO_TRANSFORM camera;

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_TIMER *frameTimer = al_create_timer(1.0 / frameFPS);

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);
	al_start_timer(frameTimer);

	GameMenu *gm = new GameMenu();
	GameScreen *gs = new GameScreen();
	MahasiswaAmbis *ma = new MahasiswaAmbis();

	al_start_timer(timer);

	while (!done) {
		sound.playMenu();
		done = gm->main_menu(menu, event_queue, stop, gameover);
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		input.update();

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		else if (events.type == ALLEGRO_EVENT_TIMER) {
			if (ma->getY() > 520) {
				menu = true;
				gameover = true;
				ma->setX(10);
				ma->setY(10);
			}
			else {
				ma->cekLompat();
			}
			if (events.timer.source == timer) {
				active = true;
				if (input.isKeyDown(ALLEGRO_KEY_UP) && ma->getJump()) {
					ma->lompat();
					sound.playJump();

				}

				if (input.isKeyDown(ALLEGRO_KEY_SPACE) && ma->getJump()){
					ma->doubleJump();
					sound.playJump();
					cout << "doublejump" << endl;
				}

				else if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
					ma->maju();
				}
				else if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
					ma->mundur();
				} 
				else if (input.isKeyDown(ALLEGRO_KEY_ESCAPE)) {
					stop = true;
					menu = true;
				}
				else {
					ma->getVel();
					active = false;
				}

				if (gameover) {
					gs->CameraUpdate(cameraPosition, 0, 0, 64, 64);
				}
				else {
					gs->CameraUpdate(cameraPosition, ma->getX(), 0, 64, 64);
				}

				al_identity_transform(&camera);
				al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
				al_use_transform(&camera);

				//===collision=============
				ma->cekGorengan(&gr);
				ma->cekBuku(&buku);
				ma->cekKoin(&koin);
				ma->cekKucing(&kucing);
				
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
			draw = true;
		}

		if (draw) {
			gs->draw();

			//==============show object============================
			//gr[0]->draw(100, 300);
			//gr[1]->draw(300, 350);

			//panjang map = 4096
			gr[0]->draw(1500, 250);
			gr[1]->draw(2900, 150);


			kucing[0]->draw(500,415);
			kucing[1]->draw(1100,415);
			kucing[2]->draw(2300,415);
			kucing[3]->draw(2000, 415);
			kucing[4]->draw(2150, 415);

			buku[0]->draw(100, 300);
			buku[1]->draw(140, 300);
			buku[2]->draw(180, 300);
			buku[3]->draw(1000, 270);
			buku[4]->draw(1040, 270);
			buku[5]->draw(1080, 270);
			buku[6]->draw(2100, 200);
			buku[7]->draw(2200, 200);
			buku[8]->draw(2300, 200);
			buku[9]->draw(2400, 200);
			buku[10]->draw(3000, 250);
			buku[11]->draw(3040, 250);
			buku[12]->draw(3080, 250);
			buku[13]->draw(3500, 300);
			buku[14]->draw(3540, 300);
			
			koin[0]->draw(1300, 300);
			koin[1]->draw(1800, 300);
			koin[2]->draw(3300, 300);
			koin[3]->draw(400, 210);

			//==============show object============================



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
	

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(frameTimer);
	al_destroy_event_queue(event_queue);
}

