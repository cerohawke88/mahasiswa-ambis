#pragma once
#include "Mahasiswa.h"
#include "SoundManager.h"
#include "Gorengan.h"
#include "Koin.h"
#include "Buku.h"
#include "Kucing.h"
#include "MahasiswaMusuh.h"
#include <vector>
#include <iostream>
using namespace std;

class MahasiswaAmbis :
	public Mahasiswa
{
private:
	int score;
	int nyawa;
	int pointBuku;
	int totalscore1;
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
	void cekGorengan(vector<Gorengan*> *gr);
	void cekKoin(vector<Koin*> *koin);
	void cekBuku(vector<Buku*> *buku);
	void cekMusuh(vector<MahasiswaMusuh*> *musuh);
	void cekKucing(vector<Kucing*> *kucing);
	void cekJatuh();
	void cekFinish();
	int getNyawa();
	void plusNyawa(int a);
	void minNyawa(int a);
	int  getScore();
	void plusScore(int b);
	void totalScore1();
	void totalScore2();
	void totalScore3();
	void totalScore4();
};

