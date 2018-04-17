#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	
}


GameObject::~GameObject()
{
//
	al_destroy_bitmap(image);
	algif_destroy_animation(gif);
}