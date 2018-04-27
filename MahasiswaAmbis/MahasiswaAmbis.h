#pragma once
#include "Mahasiswa.h"
#include "SoundManager.h"
#include "Gorengan.h"
#include "Koin.h"
#include "Buku.h"
#include "Kucing.h"
#include "MahasiswaMusuh.h"
#include "PostGame.h"
#include "Boss.h"
#include <vector>
#include <iostream>
using namespace std;

class MahasiswaAmbis :
	public Mahasiswa
{
private:
	float score;
	int nyawa;
	int pointBuku;
	float totalscorestage1;
	int totalscore1;
	int koin;
	float bestscore;

	SoundManager sound;
	MahasiswaMusuh *mu;
	PostGame *pg = new PostGame();
public:
	MahasiswaAmbis();
	~MahasiswaAmbis();

	void afterGO();
	float getY();
	float getX();
	void setY(float x);
	void setX(float y);
	float getVel();
	bool getJump();
	bool getDoubleJump();
	void doubleJump();
	void lompat();
	void maju(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level);
	void mundur(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level);
	void cekLompat(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level, vector<Boss*> *boss);
	void setSourceX(float x);
	void addSourceX(float x);
	float getSourceX();
	int getWidth();
	int getMoveSpeed();
	void drawReg(int);
	void cekGorengan(vector<Gorengan*> *gr, int& level);
	void cekKoin(vector<Koin*> *koin, int& level);
	void cekBuku(vector<Buku*> *buku, int& level);
	void cekMusuh(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level);
	void cekKucing(vector<Kucing*> *kucing, bool& menu, int& validasi_menu, int& xcu, int& level);
	void cekJatuh();
	void cekFinish(ALLEGRO_EVENT_QUEUE *queue);
	int getNyawa();
	void plusNyawa(int a);
	void minNyawa(int a);
	float getScore();
	void plusScore(float b);
	void totalScore1(float a);
	float getTotalscore1();
	int getCoin();
	void minCoin(int c);
	void plusCoin(int c);
	void totalScore1();
	void totalScore2();
	float getTotalscore2();
	void totalScore3();
	float getTotalscore3();
	void totalScore4();
	float getTotalscore4();

	float highscore();
	float getHighscore();
};