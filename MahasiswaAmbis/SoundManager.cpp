#include "stdafx.h"
#include "SoundManager.h"


SoundManager::SoundManager()
{
	al_install_audio();
	al_init_acodec_addon();	
	al_reserve_samples(8);
	menu = al_load_sample("sound_menu.wav");
	jump = al_load_sample("jump.ogg");
	eat = al_load_sample("eat.ogg");
	coin = al_load_sample("coin.ogg");
	cat = al_load_sample("cat.ogg");
	book = al_load_sample("book.ogg");
	gameover = al_load_sample("GameOver.ogg");
	complete = al_load_sample("StageComplete.ogg");

	menu_inst = al_create_sample_instance(menu);
	al_set_sample_instance_playmode(menu_inst, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(menu_inst, al_get_default_mixer());

	eat_inst = al_create_sample_instance(eat);
	al_set_sample_instance_playmode(eat_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(eat_inst, al_get_default_mixer());
	
	book_inst = al_create_sample_instance(book);
	al_set_sample_instance_playmode(book_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(book_inst, al_get_default_mixer());	
	
	gameover_inst = al_create_sample_instance(gameover);
	al_set_sample_instance_playmode(gameover_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(gameover_inst, al_get_default_mixer());	
	
	complete_inst = al_create_sample_instance(complete);
	al_set_sample_instance_playmode(complete_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(complete_inst, al_get_default_mixer());
}


SoundManager::~SoundManager()
{
	al_destroy_sample(menu);
}

void SoundManager::playMenu() {
	//al_play_sample(menu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, 0);
	al_play_sample_instance(menu_inst);
}

void SoundManager::stopMenu()
{
	al_stop_sample_instance(menu_inst);
}

void SoundManager::playBook() {
	al_play_sample_instance(book_inst);
}

void SoundManager::playGameover()
{
	al_play_sample_instance(gameover_inst);
}

void SoundManager::stopGameover()
{
	al_stop_sample_instance(gameover_inst);
}

void SoundManager::stopComplete()
{
	al_stop_sample_instance(complete_inst);
}

void SoundManager::playComplete()
{
	al_play_sample(complete, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

void SoundManager::playJump() {
	al_play_sample(jump, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

void SoundManager::playCoin() {
	al_play_sample(coin, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

void SoundManager::playEat() {
	//al_play_sample(eat, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
	al_play_sample_instance(eat_inst);
}

void SoundManager::playCat() {
	al_play_sample(cat, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}


