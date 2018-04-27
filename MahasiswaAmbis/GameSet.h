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

class GameSet
{
public:
	GameSet();
	~GameSet();

	void setValidasiTrue(vector<MahasiswaMusuh*> *musuh, vector<Gorengan*> *gr, vector<Kucing*> *kucing, vector<Buku*> *buku, vector<Koin*> *koin, vector<Boss*> *boss);
};

