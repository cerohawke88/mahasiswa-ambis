#include "stdafx.h"
#include "Koin.h"


Koin::Koin()
{
	//Gorengan::image = al_load_bitmap("Gorengan-fix.png");
	gif = algif_load_animation("Coin.gif");
	Koin::x = 10;
	Koin::y = 402;
}


Koin::~Koin()
{
}

void Koin::drawReg() {
	//al_draw_bitmap_region(image, al_get_bitmap_width(image)/4, al_get_bitmap_height(image), 64, 64, x, y, null);
}

void Koin::draw(int gorX, int gorY)
{
	//al_draw_bitmap(Gorengan::image, gorX, gorY, NULL);
	al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), gorX, gorY, NULL);
}


void Koin::plusY(float y)
{
	Koin::y += y;
}

void Koin::minY(float y)
{
	Koin::y -= y;
}

int Koin::getMoveSpeed()
{
	return Koin::y;
}

float Koin::getY()
{
	return Koin::y;
}

float Koin::getX()
{
	return Koin::x;
}

bool Koin::getJump() {
	return true;
}

void Koin::lompat()
{

}

float Koin::getVel() {
	return 0;
}

void Koin::plusX(float x)
{
	Koin::x += x;
}

void Koin::maju()
{
	velocityX = y;
}

void Koin::mundur()
{
	Koin::y = -y;
}

void Koin::minX(float x)
{
	Koin::x -= x;
}

void Koin::cekLompat()
{

}

int Koin::getWidth()
{
	return al_get_bitmap_width(image);
}

void Koin::setSourceX(float x)
{
	Koin::sourceX = x;
}

void Koin::addSourceX(float x)
{
	Koin::sourceX += x;
}

float Koin::getSourceX()
{
	return Koin::sourceX;
}

