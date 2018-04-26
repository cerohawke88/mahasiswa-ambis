#pragma once
#include "stdafx.h"
#include <allegro5\allegro5.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "MahasiswaAmbis.h"
#include "MahasiswaMusuh.h"
#include "GameScreen.h"
#include "GameMenu.h"
#include "Gorengan.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Koin.h"
#include "Buku.h"
#include "Kucing.h"
#include "Saveload.h"

class AllegClass
{
public:
	AllegClass();
	~AllegClass();

	const float FPS = 60.0;
	const float frameFPS = 15.0;

	void init();
};

