#pragma once
#include "Mahasiswa.h"
#include "Rintangan.h"
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
	ALLEGRO_BITMAP *mati;
};

