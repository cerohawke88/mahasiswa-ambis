#pragma once
#include "Mahasiswa.h"
#include "SoundManager.h"
#include "Gorengan.h"
#include <vector>
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
	void setY(float x);
	void setX(float y);
	float getVel();
	bool getJump();
	bool getDoubleJump();
	void doubleJump();
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
	void cekItem(vector<Gorengan*> *gr);
	void cekJatuh();
	void cekFinish();
	int getNyawa();
	void plusNyawa(int a);
};

