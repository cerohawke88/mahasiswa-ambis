#pragma once
#include "GameObject.h"
class Rintangan :
	public GameObject
{
public:
	Rintangan();
	~Rintangan();
	string nama;
	int jenisRintangan;
	virtual void maju() = 0;
	virtual void mundur() = 0;
	virtual void drawReg(int) = 0;

};

