#pragma once
#include <allegro5\allegro.h>
#include "algif.h"
class GameObject
{
protected:
	ALLEGRO_BITMAP *image;
	ALGIF_ANIMATION *gif;
	float x, y, sourceX, sourceY;
	float velocityX, velocityY;
	float gravity;
public:
	GameObject();
	~GameObject();

	virtual float getY() = 0;
	virtual float getX() = 0;
	virtual void setSourceX(float x) = 0;
	virtual void addSourceX(float x) = 0;
	virtual float getSourceX() = 0;
	virtual int getWidth() = 0;
	virtual int getMoveSpeed() = 0;
	//virtual void draw() = 0;
};

