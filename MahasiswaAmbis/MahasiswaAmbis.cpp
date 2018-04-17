#include "stdafx.h"
#include "MahasiswaAmbis.h"
#include "SoundManager.h"


MahasiswaAmbis::MahasiswaAmbis()
{
	MahasiswaAmbis::image = al_load_bitmap("Mahasiswa.png");
	MahasiswaAmbis::moveSpeed = 5;
	MahasiswaAmbis::x = 10;
	MahasiswaAmbis::y = 10;
	MahasiswaAmbis::sourceX = 64;
	MahasiswaAmbis::sourceY = 0;
	MahasiswaAmbis::jump = false;
	MahasiswaAmbis::jumpSpeed = 15;
	MahasiswaAmbis::velocityX = MahasiswaAmbis::velocityY = 0;
	MahasiswaAmbis::gravity = 1;
}

void MahasiswaAmbis::drawReg(int n) {
	al_draw_bitmap_region(image, sourceX, sourceY * al_get_bitmap_height(image) / 2, 64, 64, x, y, n);
}


int MahasiswaAmbis::getMoveSpeed()
{
	return MahasiswaAmbis::moveSpeed;
}

float MahasiswaAmbis::getY()
{
	return this->y;
}

float MahasiswaAmbis::getX()
{
	return MahasiswaAmbis::x;
} 

bool MahasiswaAmbis::getJump() {
	return jump;
}

void MahasiswaAmbis::lompat()
{
	velocityY = -jumpSpeed;
	jump = false;	
	sound.playJump();
}

float MahasiswaAmbis::getVel() {
	return velocityX = 0;
}

void MahasiswaAmbis::maju()
{
	velocityX = moveSpeed;
	this->cekJatuh();
}

void MahasiswaAmbis::mundur()
{
	velocityX = -moveSpeed;
}

void MahasiswaAmbis::cekJatuh()
{
	int x = 0;
	
}

void MahasiswaAmbis::cekLompat()
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


int MahasiswaAmbis::getWidth()
{
	return al_get_bitmap_width(image);
}

void MahasiswaAmbis::setSourceX(float x)
{
	MahasiswaAmbis::sourceX = x;
}

void MahasiswaAmbis::addSourceX(float x)
{
	MahasiswaAmbis::sourceX += x;
}

float MahasiswaAmbis::getSourceX()
{
	return MahasiswaAmbis::sourceX;
}

int MahasiswaAmbis::cekItem()
{
	if (this->x>70 && this->x<120 && this->y> 290 && this->y< 310) {
		sound.playEat();
		cout << "gor1\n";
		return 1;
	} else if (this->x>270 && this->x<320 && this->y> 340 && this->y< 360) {
		sound.playEat();
		cout << "gor2\n";
		return 2;
	}
	else if (this->x>570 && this->x<620 && this->y> 290 && this->y< 310) {
		sound.playEat();
		cout << "gor3\n";
		return 3;
	}
	else {
		return 0;
	}
}

void MahasiswaAmbis::cekFinish()
{
	
}

MahasiswaAmbis::~MahasiswaAmbis()
{
}