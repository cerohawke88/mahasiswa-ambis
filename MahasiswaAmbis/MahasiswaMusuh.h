#pragma once

#include <allegro5\allegro5.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <stdio.h>
#include <allegro5\allegro_ttf.h>
#include "Mahasiswa.h"
#include "Rintangan.h"
#include <allegro5\allegro_image.h>
#include "algif.h"
class MahasiswaMusuh :
	public Mahasiswa
{
public:
	MahasiswaMusuh();
	~MahasiswaMusuh();
	void diinjak(int x, int y);
	void maju();
	void mundur();
	float getY();
	float getX();
	void setSourceX(float x);
	void addSourceX(float x);
	float getSourceX();
	int getWidth();
	int getMoveSpeed();
	void draw(int x, int y);
	void cekJatuh();
	void cekLompat();
	void setValidasi(bool x);
	bool getValidasi();
private:
	bool validasi;
	ALGIF_ANIMATION *gif_mati;
};

