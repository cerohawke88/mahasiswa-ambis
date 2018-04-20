#include "stdafx.h"
#include "Buku.h"


Buku::Buku()
{
	//Buku::image = al_load_bitmap("Buku-fix.png");
	gif = algif_load_animation("Book.gif");
	Buku::x = 10;
	Buku::y = 402;
	Buku::validasi = true;
}


Buku::~Buku()
{
}

void Buku::drawReg() {
	//al_draw_bitmap_region(image, al_get_bitmap_width(image)/4, al_get_bitmap_height(image), 64, 64, x, y, null);
}

void Buku::draw(int x, int y)
{
	if (Buku::validasi) {
		al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), x, y, NULL);
	}
}


void Buku::plusY(float y)
{
	Buku::y += y;
}

void Buku::minY(float y)
{
	Buku::y -= y;
}

int Buku::getMoveSpeed()
{
	return Buku::y;
}

float Buku::getY()
{
	return Buku::y;
}

float Buku::getX()
{
	return Buku::x;
}

bool Buku::getJump() {
	return true;
}

void Buku::lompat()
{

}

float Buku::getVel() {
	return 0;
}

void Buku::plusX(float x)
{
	Buku::x += x;
}

void Buku::maju()
{
	velocityX = y;
}

void Buku::mundur()
{
	velocityX = -y;
}

void Buku::minX(float x)
{
	Buku::x -= x;
}

void Buku::cekLompat()
{

}

int Buku::getWidth()
{
	return al_get_bitmap_width(image);
}

void Buku::setSourceX(float x)
{
	Buku::sourceX = x;
}

void Buku::addSourceX(float x)
{
	Buku::sourceX += x;
}

float Buku::getSourceX()
{
	return Buku::sourceX;
}

void Buku::setValidasi(bool x)
{
	Buku::validasi = x;
}

bool Buku::getValidasi()
{
	return Buku::validasi;
}

