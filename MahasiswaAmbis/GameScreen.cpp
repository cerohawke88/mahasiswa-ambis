#include "stdafx.h"
#include "GameScreen.h"



GameScreen::GameScreen()
{
	background1 = al_load_bitmap("mapp.png");
	background2 = al_load_bitmap("DESIGN/maplevel2.png");
	font = al_load_font("font.ttf", 20, 0);
	al_init_ttf_addon();
	color.menu = al_map_rgb(122, 113, 143);
	color.enter = al_map_rgb(0, 0, 0);
	color.white = al_map_rgb(255, 255, 255);
	gif_koin = algif_load_animation("Coin.gif");
	gif_gorengan = algif_load_animation("gor.gif");
	gif_buku = algif_load_animation("Book.gif");
	gif_life = algif_load_animation("life.gif");
	tooltip = al_load_bitmap("tooltip.png");
	tooltip2 = al_load_bitmap("tooltip2.png");
	tooltip3 = al_load_bitmap("tooltip3.png");
	tooltip4 = al_load_bitmap("tooltip4.png");
	tooltip5 = al_load_bitmap("tooltip5.png");
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

void GameScreen::showKoin(int x, int width, MahasiswaAmbis *ma, int level)
{

	int xx;
	xx = -(ScreenWidth / 2) + (x + 300 / 2);
	int score,koin,nyawa;
	score = (int)ma->getScore();
	koin = ma->getCoin();
	nyawa = ma->getNyawa();

	if (xx < 100) {
		xx = 100;
	}

	if (x > 3695 && level == 1) {
		al_draw_bitmap(algif_get_bitmap(gif_koin, al_get_time()), 3515, 5, NULL);
		al_draw_textf(font, color.enter, 3575, 30, ALLEGRO_ALIGN_CENTRE, "%d ", koin);

		al_draw_bitmap(algif_get_bitmap(gif_buku, al_get_time()), 3605, 5, NULL);
		al_draw_textf(font, color.enter, 3665, 30, ALLEGRO_ALIGN_CENTRE, "%d ", score);

		al_draw_bitmap(algif_get_bitmap(gif_life, al_get_time()), 3695, 20, NULL);
		al_draw_textf(font, color.enter, 3755, 30, ALLEGRO_ALIGN_CENTRE, "%d ", nyawa);
	} 
	else if (x > 2670 && level == 2) {
		al_draw_bitmap(algif_get_bitmap(gif_koin, al_get_time()), 2490, 5, NULL);
		al_draw_textf(font, color.enter, 2550, 30, ALLEGRO_ALIGN_CENTRE, "%d ", koin);

		al_draw_bitmap(algif_get_bitmap(gif_buku, al_get_time()), 2580, 5, NULL);
		al_draw_textf(font, color.enter, 2640, 30, ALLEGRO_ALIGN_CENTRE, "%d ", score);

		al_draw_bitmap(algif_get_bitmap(gif_life, al_get_time()), 2670, 20, NULL);
		al_draw_textf(font, color.enter, 2750, 30, ALLEGRO_ALIGN_CENTRE, "%d ", nyawa);
	}
	else {
		al_draw_bitmap(algif_get_bitmap(gif_koin, al_get_time()), xx - 60, 5, NULL);
		al_draw_textf(font, color.enter, xx, 30, 0, "%d ", koin);
			
		al_draw_bitmap(algif_get_bitmap(gif_buku, al_get_time()), xx + 30, 5, NULL);
		al_draw_textf(font, color.enter, xx + 90, 30, 0, "%d ", score);

		al_draw_bitmap(algif_get_bitmap(gif_life, al_get_time()), xx + 110, 7, NULL);
		al_draw_textf(font, color.enter, xx + 170, 30, 0, "%d ", nyawa );
	}

	
}

void GameScreen::CameraUpdate(float *cameraPosition, float x, float y, int widht, int height, int level)
{
	cameraPosition[0] = -(ScreenWidth / 2) + (x + widht / 2);
	cameraPosition[1] = -(ScreenHeight / 2) + (y + height / 2);

	if (cameraPosition[0] < 0) {
		cameraPosition[0] = 0;
	}
	if (cameraPosition[1] < 0) {
		cameraPosition[1] = 0;
	}
	if (level == 1) {
		if (x > 3695) {
			cameraPosition[0] = 4096 - 700;
		}
	}
	else if (level == 2) {
		if (x > 2670) {
			cameraPosition[0] = 3072 - 700;
		}
	}
	
}

void GameScreen::draw(int level)
{
	if (level==1) {
		al_draw_bitmap(GameScreen::background1, 0, 0, NULL);
	}
	else if(level==2) {
		al_draw_bitmap(GameScreen::background2, 0, 0, NULL);
	}
}

void GameScreen::eventkey(ALLEGRO_EVENT events)
{
	al_wait_for_event(event_queue, &events);
}


void GameScreen::drawAllObject(vector<MahasiswaMusuh*> *musuh, vector<Gorengan*> *gr, vector<Kucing*> *kucing, vector<Buku*> *buku, vector<Koin*> *koin, int& level, vector<Boss*> *boss)
{
	if (level == 1) {
		gr->at(0)->draw(1500, 250);
		gr->at(1)->draw(2900, 150);

		kucing->at(0)->draw(500, 415);
		kucing->at(1)->draw(1100, 415);

		kucing->at(2)->draw(2250, 415);
		kucing->at(3)->draw(1950, 415);
		kucing->at(4)->draw(2100, 415);

		musuh->at(0)->draw(1380, 375);

		buku->at(0)->draw(100, 300);
		buku->at(1)->draw(140, 300);
		buku->at(2)->draw(180, 300);
		buku->at(3)->draw(1000, 270);
		buku->at(4)->draw(1040, 270);
		buku->at(5)->draw(1080, 270);
		buku->at(6)->draw(2100, 200);
		buku->at(7)->draw(2200, 200);
		buku->at(8)->draw(2300, 200);
		buku->at(9)->draw(2400, 200);
		buku->at(10)->draw(3000, 250);
		buku->at(11)->draw(3040, 250);
		buku->at(12)->draw(3080, 250);
		buku->at(13)->draw(3500, 300);
		buku->at(14)->draw(3540, 300);

		koin->at(0)->draw(1300, 300);
		koin->at(1)->draw(1800, 300);
		koin->at(2)->draw(3300, 300);
		koin->at(3)->draw(400, 210);
	}
	else if (level == 2){
		boss->at(0)->draw(1500, 250);
		boss->at(1)->draw(2900, 150);


		gr->at(0)->draw(620, 210);
		gr->at(1)->draw(2900, 150);

		kucing->at(0)->draw(620, 410);
		kucing->at(1)->draw(745, 410);
		kucing->at(2)->draw(900, 410);
		kucing->at(3)->draw(1580, 410);
		kucing->at(4)->draw(1785, 410);
		

		musuh->at(0)->draw(1350, 370);

		buku->at(0)->draw(100, 235);
		buku->at(1)->draw(145, 220);
		buku->at(2)->draw(185, 205);
		buku->at(3)->draw(1000, 270);
		buku->at(4)->draw(1040, 270);
		buku->at(5)->draw(1080, 270);
		buku->at(6)->draw(1485, 160);
		buku->at(7)->draw(2100, 200);
		buku->at(8)->draw(2200, 200);
		buku->at(9)->draw(2300, 200);
		buku->at(10)->draw(1660, 100);

		/*
		buku->at(9)->draw(2400, 200);
		buku->at(11)->draw(3040, 250);
		buku->at(12)->draw(3080, 250);
		buku->at(13)->draw(3500, 300);
		buku->at(14)->draw(3540, 300);
		*/
		koin->at(0)->draw(1300, 300);
		koin->at(1)->draw(1800, 300);
		koin->at(2)->draw(900, 195);
		koin->at(3)->draw(270, 210);
	}
}