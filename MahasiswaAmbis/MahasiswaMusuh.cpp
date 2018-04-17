#include "stdafx.h"
#include "MahasiswaMusuh.h"


MahasiswaMusuh::MahasiswaMusuh()
{
	image = al_load_bitmap("musuh.png");
	moveSpeed = 2.5;
	x = 10;
	y = 402;
	sourceX = 64;
	sourceY = 0;
	jump = false;
	jumpSpeed = 15;
	velocityX = velocityY = 0;
	gravity = 1;
}


MahasiswaMusuh::~MahasiswaMusuh()
{
}

void MahasiswaMusuh::diinjak() {

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

void MahasiswaMusuh::drawReg(int x, int y, int n)
{
	al_draw_bitmap_region(image, sourceX, sourceY * al_get_bitmap_height(image) / 2, 64, 64, x, y, n);
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




