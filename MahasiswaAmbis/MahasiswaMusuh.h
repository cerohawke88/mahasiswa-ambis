#pragma once
#include "Mahasiswa.h"
#include "Rintangan.h"
class MahasiswaMusuh :
	public Mahasiswa
{
public:
	MahasiswaMusuh();
	~MahasiswaMusuh();
	void diinjak();
	void maju();
	void mundur();
	float getY();
	float getX();
	void setSourceX(float x);
	void addSourceX(float x);
	float getSourceX();
	int getWidth();
	int getMoveSpeed();
	void drawReg(int x, int y, int n);
	void cekJatuh();
	void cekLompat();
};

