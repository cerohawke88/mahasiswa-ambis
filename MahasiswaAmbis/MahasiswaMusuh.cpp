#include "stdafx.h"
#include "MahasiswaMusuh.h"


MahasiswaMusuh::MahasiswaMusuh()
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
	MahasiswaMusuh::validasi = true;
}


MahasiswaMusuh::~MahasiswaMusuh()
{
	algif_destroy_animation(gif);
}

void MahasiswaMusuh::diinjak(int x, int y) {

}

void MahasiswaMusuh::maju()
{
	velocityX = moveSpeed;
}

void MahasiswaMusuh::mundur()
{
	velocityX = -moveSpeed;
}

float MahasiswaMusuh::getY()
{
	return y;
}

float MahasiswaMusuh::getX()
{
	return x;
}

void MahasiswaMusuh::setSourceX(float x)
{
	sourceX = x;
}

void MahasiswaMusuh::addSourceX(float x)
{
	sourceX += x;
}

float MahasiswaMusuh::getSourceX()
{
	return sourceX;
}

int MahasiswaMusuh::getWidth()
{
	return al_get_bitmap_width(image);
}

int MahasiswaMusuh::getMoveSpeed()
{
	return moveSpeed;
}

void MahasiswaMusuh::draw(int x, int y)
{
	if (MahasiswaMusuh::validasi) {
		al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), x, y, NULL);
	}
	else {
		///al_draw_bitmap(image, x, y, NULL);
		al_draw_bitmap(algif_get_bitmap(gif_mati, al_get_time()), x, y, NULL);
	}
}


void MahasiswaMusuh::cekJatuh()
{
	int x = 0;
}

void MahasiswaMusuh::cekLompat()
{
	if (!jump)
		velocityY += gravity;
	else
		velocityY = 0;

	x += velocityX;
	y += velocityY;

	if (x > 400 && x < 450 && y >= 402) {
		y += 15;
		cout << y << endl;
		cout << "jatuh\n";
	}
	else if (x > 1790 && x < 1820 && y >= 402) {
		y += 15;
		cout << y << endl;
		cout << "jatuh\n";
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

void MahasiswaMusuh::setValidasi(bool x)
{
	MahasiswaMusuh::validasi = x;
}

bool MahasiswaMusuh::getValidasi()
{
	return MahasiswaMusuh::validasi;
}




