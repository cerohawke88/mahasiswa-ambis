#pragma once
#include "Mahasiswa.h"
#include "SoundManager.h"
#include <iostream>
using namespace std;

class MahasiswaAmbis :
	public Mahasiswa
{
private:
	int nyawa;
	int pointBuku;
	SoundManager sound;
public:
	MahasiswaAmbis();
	~MahasiswaAmbis();


	float getY();
	float getX();
	float getVel();
	bool getJump();
	void lompat();
	void maju();
	void mundur();
	void cekLompat();
	void setSourceX(float x);
	void addSourceX(float x);
	float getSourceX();
	int getWidth();
	int getMoveSpeed();
	void drawReg(int);
	int cekItem();
	void cekJatuh();
	void cekFinish();

};

