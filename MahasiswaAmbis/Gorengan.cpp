#include "stdafx.h"
#include "Gorengan.h"


Gorengan::Gorengan()
{
	//Gorengan::image = al_load_bitmap("Gorengan-fix.png");
	gif = algif_load_animation("Gor.gif");
	Gorengan::x = 10;
	Gorengan::y = 402;
	Gorengan::validasi = true;
}


Gorengan::~Gorengan()
{
}

void Gorengan::drawReg() {
	//al_draw_bitmap_region(image, al_get_bitmap_width(image)/4, al_get_bitmap_height(image), 64, 64, x, y, null);
}

void Gorengan::draw(int x, int y)
{
	if (Gorengan::validasi) {
		al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), x, y, NULL);
	}
}


void Gorengan::plusY(float y)
{
	Gorengan::y += y;
}

void Gorengan::minY(float y)
{
	Gorengan::y -= y;
}

int Gorengan::getMoveSpeed()
{
	return Gorengan::y;
}

float Gorengan::getY()
{
	return Gorengan::y;
}

float Gorengan::getX()
{
	return Gorengan::x;
}

bool Gorengan::getJump() {
	return true;
}

void Gorengan::lompat()
{
	
}

float Gorengan::getVel() {
	return 0;
}

void Gorengan::plusX(float x)
{
	Gorengan::x += x;
}

void Gorengan::maju()
{
	velocityX = y;
}

void Gorengan::mundur()
{
	velocityX = -y;
}

void Gorengan::minX(float x)
{
	Gorengan::x -= x;
}

void Gorengan::cekLompat()
{
	
}

int Gorengan::getWidth()
{
	return al_get_bitmap_width(image);
}

void Gorengan::setSourceX(float x)
{
	Gorengan::sourceX = x;
}

void Gorengan::addSourceX(float x)
{
	Gorengan::sourceX += x;
}

float Gorengan::getSourceX()
{
	return Gorengan::sourceX;
}

void Gorengan::setValidasi(bool x)
{
	Gorengan::validasi = x;
}

bool Gorengan::getValidasi()
{
	return Gorengan::validasi;
}

