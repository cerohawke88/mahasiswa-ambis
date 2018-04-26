#include "Kucing.h"
#include "stdafx.h"




Kucing::Kucing()
{
	//gambar = Kucing::image = al_load_bitmap("Kucing-fix.png");
	gif = algif_load_animation("Kucing.gif");
	Kucing::x = 10;
	Kucing::y = 402;
	Kucing::validasi = true;
}

void Kucing::afterGO()
{
	Kucing::validasi = true;
}


Kucing::~Kucing()
{
}

void Kucing::drawReg() {
	//al_draw_bitmap_region(image, al_get_bitmap_width(image)/4, al_get_bitmap_height(image), 64, 64, x, y, null);
}

void Kucing::draw(int x, int y)
{
	al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), x, y, NULL);
	
}


void Kucing::plusY(float y)
{
	Kucing::y += y;
}

void Kucing::minY(float y)
{
	Kucing::y -= y;
}

int Kucing::getMoveSpeed()
{
	return Kucing::y;
}

float Kucing::getY()
{
	return Kucing::y;
}

float Kucing::getX()
{
	return Kucing::x;
}

bool Kucing::getJump() {
	return true;
}

void Kucing::lompat()
{

}

float Kucing::getVel() {
	return 0;
}

void Kucing::plusX(float x)
{
	Kucing::x += x;
}

void Kucing::maju()
{
	velocityX = y;
}

void Kucing::mundur()
{
	velocityX = -y;
}

void Kucing::minX(float x)
{
	Kucing::x -= x;
}

void Kucing::cekLompat()
{

}

int Kucing::getWidth()
{
	return al_get_bitmap_width(image);
}

void Kucing::setSourceX(float x)
{
	Kucing::sourceX = x;
}

void Kucing::addSourceX(float x)
{
	Kucing::sourceX += x;
}

float Kucing::getSourceX()
{
	return Kucing::sourceX;
}

void Kucing::setValidasi(bool x)
{
	Kucing::validasi = x;
}

bool Kucing::getValidasi()
{
	return Kucing::validasi;
}
