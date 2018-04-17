#include "stdafx.h"
#include "GameInit.h"


GameInit::GameInit()
{
	al_install_keyboard();
	al_init_image_addon();
}


GameInit::~GameInit()
{
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(frameTimer);
	al_destroy_event_queue(event_queue);
}

bool GameInit::getDraw()
{
	return GameInit::draw;
}

bool GameInit::getDone()
{
	return GameInit::done;
}

void GameInit::setDraw(bool truevalue)
{
	GameInit::draw = truevalue;
}

void GameInit::init()
{
	timer = al_create_timer(1.0 / FPS);
	frameTimer = al_create_timer(1.0 / frameFPS);
	
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);
	al_start_timer(frameTimer);
}

void GameInit::setDisplay()
{
	display = al_create_display(ScreenWidth, ScreenHeight);
	if (!display) {
		al_show_native_message_box(NULL, "ERROR", NULL, "COULD NOT SHOW DISPLAY", NULL, NULL);
	}

	al_set_window_position(display, 200, 200);
}

void GameInit::run()
{
	ALLEGRO_EVENT events;

	al_wait_for_event(event_queue, &events);
	al_get_keyboard_state(&keyState);
	if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		done = true;
	}
	else if (events.type == ALLEGRO_EVENT_TIMER) {
		if (ma->getY() < 372) {
			ma->plusY(ma->getMoveSpeed());
		}
		if (ceklompat == 1) {
			ma->plusX(ma->getMoveSpeed());
			ceklompat = 0;
		}
		if (events.timer.source == timer) {
			active = true;
			if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
				ma->minY(10.0);
				ceklompat = 1;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
				ma->plusX(ma->getMoveSpeed());
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
				ma->minX(ma->getMoveSpeed());
			}

			else {
				active = false;
			}

			gs->CameraUpdate(cameraPosition, ma->getX(), 0, 50, 94);

			al_identity_transform(&camera);
			al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
			al_use_transform(&camera);
		}

		else if (events.timer.source == frameTimer) {
			if (active) {
				ma->addSourceX(54);
			}
			else {
				ma->setSourceX(50);
			}
			if (ma->getSourceX() >= ma->getWidth()) {
				ma->setSourceX(0);
			}
		}
		draw = true;
	}

	if (draw) {
		ma->draw();
		gs->draw();
	}
}