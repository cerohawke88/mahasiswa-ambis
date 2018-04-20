#pragma once
#include "GameObject.h"
class Buku :
	public GameObject
{
public:
	Buku();
	~Buku();

	void drawReg();
	void plusY(float y);
	void minY(float y);
	void plusX(float x);
	void minX(float x);
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
	void setValidasi(bool);
	bool getValidasi();
	//void draw();
	void draw(int x, int y);

private:
	bool validasi;
};

