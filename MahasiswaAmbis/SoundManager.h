#pragma once
#include <allegro5/allegro_audio.h>
#include <allegro5\allegro_acodec.h>
class SoundManager
{
private:
	ALLEGRO_SAMPLE * menu = NULL;
	ALLEGRO_SAMPLE * jump = NULL;
	ALLEGRO_SAMPLE * coin = NULL;
	ALLEGRO_SAMPLE * eat = NULL;
	ALLEGRO_SAMPLE * cat = NULL;
	ALLEGRO_SAMPLE_INSTANCE *menu_inst;
	ALLEGRO_SAMPLE_INSTANCE *jump_inst;
	ALLEGRO_SAMPLE_INSTANCE *coin_inst;
	ALLEGRO_SAMPLE_INSTANCE *eat_inst;
	ALLEGRO_SAMPLE_INSTANCE *cat_inst;
public:
	SoundManager();
	~SoundManager();
	void playMenu();
	void playJump();
	void playCoin();
	void playEat();
	void playCat();
};

