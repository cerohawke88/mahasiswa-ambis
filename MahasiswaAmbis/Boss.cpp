#include "Boss.h"

Boss::Boss(int setxreal)
{
	gif = algif_load_animation("musuh.gif");
	gif_mati = algif_load_animation("musuh_mati.gif");
	moveSpeed = 2.5;
	x = 10;
	y = 402;
	sourceX = 64;
	sourceY = 0;
	jump = false;
	jumpSpeed = 15;
	velocityX = velocityY = 0;
	gravity = 1;
	xreal = setxreal;
	cek = 0;
	Boss::validasi = true;
}

void Boss::afterGO(int setxreal)
{
	moveSpeed = 2.5;
	x = 10;
	y = 402;
	sourceX = 64;
	sourceY = 0;
	jump = false;
	jumpSpeed = 15;
	velocityX = velocityY = 0;
	gravity = 1;
	xreal = setxreal;
	Boss::validasi = true;
}


Boss::~Boss()
{
	algif_destroy_animation(gif);
}

void Boss::diinjak(int x, int y) {

}

void Boss::maju()
{
	velocityX = moveSpeed;
}

void Boss::mundur()
{
	velocityX = -moveSpeed;
}

float Boss::getY()
{
	return y;
}

float Boss::getX()
{
	return x;
}

void Boss::setSourceX(float x)
{
	sourceX = x;
}

void Boss::addSourceX(float x)
{
	sourceX += x;
}

float Boss::getSourceX()
{
	return sourceX;
}

int Boss::getWidth()
{
	return al_get_bitmap_width(image);
}

int Boss::getMoveSpeed()
{
	return moveSpeed;
}

void Boss::draw(int x, int y)
{
	if (xreal == 2500)
		cek = 1;
	else if (xreal == 2700)
		cek = 2;
	
	if (cek == 1)
		xreal++;
	else if (cek == 2)
		xreal--;

	if (Boss::validasi) {
		al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), xreal, 375, NULL);
	}
	else {
		///al_draw_bitmap(image, x, y, NULL);
		al_draw_bitmap(algif_get_bitmap(gif_mati, al_get_time()), x, y, NULL);
	}
}

int Boss::getXReal()
{
	return xreal;
}

void Boss::cekJatuh()
{
	int x = 0;
}

void Boss::cekLompat()
{
	if (!jump)
		velocityY += gravity;
	else
		velocityY = 0;

	x += velocityX;
	y += velocityY;

	if (x > 400 && x < 450 && y >= 402) {
		y += 15;
	}
	else if (x > 1790 && x < 1820 && y >= 402) {
		y += 15;
	}
	else {
		//cout << "hush" << endl;
		jump = (y + 64 >= 466);

		if (jump) {
			y = 466 - 64;
			//sound.playJump();
		}
	}
}

void Boss::setValidasi(bool x)
{
	Boss::validasi = x;
}

bool Boss::getValidasi()
{
	return Boss::validasi;
}

