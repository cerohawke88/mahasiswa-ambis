#pragma once
#include <allegro5\allegro5.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <stdio.h>
#include <allegro5\allegro_ttf.h>
#include "Mahasiswa.h"
#include <allegro5\allegro_image.h>
#include "algif.h"
#include <iostream>
using namespace std;

class Boss :
	public Mahasiswa
{
public:
	Boss(int setxreal);
	~Boss();
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
	void afterGO(int setxreal);
	int getXReal();
private:
	bool validasi;
	int xreal;
	int cek;
	ALGIF_ANIMATION *gif_mati;
};

