#pragma once
#include "GameObject.h"


class Mahasiswa : public GameObject
{
protected:
	float moveSpeed;
	int dir;
	bool jump;
	float jumpSpeed;
	float jumpSpeedDouble;
	bool doublejump;

public:
	Mahasiswa();
	~Mahasiswa();


};

