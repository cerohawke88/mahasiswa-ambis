#pragma once
#include "GameObject.h"
class Gorengan : public GameObject
{
public:
	Gorengan();
	~Gorengan();

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
	//void draw();
	void draw(int gorX, int gorY);
private:
	int nyawa;
};

