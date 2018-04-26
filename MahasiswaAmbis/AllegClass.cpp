#include "AllegClass.h"



AllegClass::AllegClass()
{
}


AllegClass::~AllegClass()
{
}

void AllegClass::init()
{
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();

}
