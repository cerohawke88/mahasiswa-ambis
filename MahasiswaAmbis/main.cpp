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

int main()
{
	ALLEGRO_DISPLAY *display;
	const float FPS = 60.0;
	const float frameFPS = 15.0;

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
	
	Koin *ko = new Koin();
	bool done = false, draw = true, active = false;
	float cameraPosition[2] = { 0,0 };
	bool gameover = false;
	bool menu = true;
	bool stop = false;

	//set gorengan
	vector<Gorengan*> gr;
	gr.push_back(new Gorengan);
	gr.push_back(new Gorengan);
	gr.push_back(new Gorengan);
	/*for (int j = 0; j < 3; j++) {
		gr[j] = new Gorengan();
	}*/
	
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
	MahasiswaMusuh *mu = new MahasiswaMusuh();
	MahasiswaAmbis *ma = new MahasiswaAmbis();

	
	al_start_timer(timer);

	while (!done) {
		sound.playMenu();
		gm->main_menu(menu, event_queue, stop, gameover);
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		input.update();

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE || input.isKeyPressed(events, ALLEGRO_KEY_ESCAPE)) {
			done = true;
		}
		else if (events.type == ALLEGRO_EVENT_TIMER) {
			ma->cekLompat();
			if (ma->getY() > 450) {
				menu = true;
				gameover = true;
			}
			if (events.timer.source == timer) {
				active = true;
				if (input.isKeyDown(ALLEGRO_KEY_UP) && ma->getJump()) {
					ma->lompat();
					sound.playJump();
				}
				else if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
					ma->maju();
				}
				else if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
					ma->mundur();
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
				ma->cekItem(&gr);
				
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
			gr[0]->draw(100, 300);
			gr[1]->draw(300, 350);
			gr[2]->draw(600, 300);
			//koin

			mu->drawReg(600, 300, 1);
				
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

