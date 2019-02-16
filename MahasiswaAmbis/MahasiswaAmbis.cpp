#include "stdafx.h"
#include "MahasiswaAmbis.h"
#include "SoundManager.h"

MahasiswaAmbis::MahasiswaAmbis()
{
	MahasiswaAmbis::image = al_load_bitmap("Mahasiswa.png");
	MahasiswaAmbis::moveSpeed = 5;
	MahasiswaAmbis::x = 10;
	MahasiswaAmbis::y = 10;
	MahasiswaAmbis::sourceX = 64;
	MahasiswaAmbis::sourceY = 0;
	MahasiswaAmbis::jump = false;
	MahasiswaAmbis::doublejump = false;
	MahasiswaAmbis::jumpSpeed = 15;
	MahasiswaAmbis::jumpSpeedDouble = 23;
	MahasiswaAmbis::velocityX = MahasiswaAmbis::velocityY = 0;
	MahasiswaAmbis::gravity = 1;
	MahasiswaAmbis::nyawa = 3;
	MahasiswaAmbis::score = 0;
	MahasiswaAmbis::totalscorestage1 = 0;
	MahasiswaAmbis::bestscore = 0;
	MahasiswaAmbis::koin = 0;
}

void MahasiswaAmbis::afterGO()
{
	MahasiswaAmbis::moveSpeed = 5;
	MahasiswaAmbis::x = 10;
	MahasiswaAmbis::y = 10;
	MahasiswaAmbis::sourceX = 64;
	MahasiswaAmbis::sourceY = 0;
	MahasiswaAmbis::jump = false;
	MahasiswaAmbis::doublejump = false;
	MahasiswaAmbis::jumpSpeed = 15;
	MahasiswaAmbis::jumpSpeedDouble = 23;
	MahasiswaAmbis::velocityX = MahasiswaAmbis::velocityY = 0;
	MahasiswaAmbis::gravity = 1;
	MahasiswaAmbis::nyawa = 3;
	MahasiswaAmbis::score = 0;
	MahasiswaAmbis::koin = 0;
	MahasiswaAmbis::totalscorestage1 = 0;
	MahasiswaAmbis::bestscore = 0;
}


void MahasiswaAmbis::drawReg(int n)
{
	al_draw_bitmap_region(image, sourceX, sourceY * al_get_bitmap_height(image) / 2, 64, 64, x, y, n);
}


int MahasiswaAmbis::getMoveSpeed()
{
	return MahasiswaAmbis::moveSpeed;
}

float MahasiswaAmbis::getY()
{
	return this->y;
}

float MahasiswaAmbis::getX()
{
	return MahasiswaAmbis::x;
} 

bool MahasiswaAmbis::getJump() {
	return jump;
}

void MahasiswaAmbis::lompat()
{
	velocityY = -jumpSpeed;
	jump = false;	
	sound.playJump();
}

void MahasiswaAmbis::doubleJump()
{
	velocityY = -jumpSpeedDouble;
	jump = false;
	sound.playJump();
}

float MahasiswaAmbis::getVel() {
	return velocityX = 0;
}

void MahasiswaAmbis::maju(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level)
{
	int cek;
	if (level == 1) {
		cek = 0;
		if (this->x >= 1350 && this->x <= 1450 && this->y >= 360) {
			if (musuh->at(0)->getValidasi() == true) {
				x -= 130;
				if (getNyawa() > 1)
				{

					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}
				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
			}
			else {
				velocityX = moveSpeed;
			}
			if (cek == 1) {
				menu = true;
				validasi_menu = 2;
				xcu = 0;
			}
		}
		else {
			if (this->x < 4000) {
				velocityX = moveSpeed;
				this->cekJatuh();
			}
		}
	}
	else if (level == 2) {
		cek = 0;
		if (this->x >= 1350 && this->x <= 1450 && this->y >= 360) {
			if (musuh->at(0)->getValidasi() == true) {
				x -= 130;
				if (getNyawa() > 1)
				{

					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}
				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
			}
			else {
				velocityX = moveSpeed;
			}
			if (cek == 1) {
				menu = true;
				validasi_menu = 2;
				xcu = 0;
			}
		}
		else {
			if (this->x < 4000) {
				velocityX = moveSpeed;
				this->cekJatuh();
			}
		}
	}
}

void MahasiswaAmbis::mundur(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level)
{
	int cek;
	if (level == 1) {
		cek = 0;
		if (this->x >= 1350 && this->x <= 1450 && this->y >= 360) {
			if (musuh->at(0)->getValidasi() == true) {
				x += 130;
				if (getNyawa() > 1)
				{
					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
			}
			else {
				velocityX = -moveSpeed;
			}
		}
		else {
			velocityX = -moveSpeed;
			this->cekJatuh();

		}

		if (cek == 1) {
			menu = true;
			validasi_menu = 2;
			xcu = 0;
		}
	}
	else if (level == 2) {
		cek = 0;
		if (this->x >= 1350 && this->x <= 1450 && this->y >= 360) {
			if (musuh->at(0)->getValidasi() == true) {
				x += 130;
				if (getNyawa() > 1)
				{

					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}
				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
			}
			else {
				velocityX = -moveSpeed;
			}
			if (cek == 1) {
				menu = true;
				validasi_menu = 2;
				xcu = 0;
			}
		}
		else {
			if (this->x < 4000) {
				velocityX = -moveSpeed;
				this->cekJatuh();
			}
		}
	}
}

void MahasiswaAmbis::cekJatuh()
{
	int x = 0;
	
}

void MahasiswaAmbis::cekLompat(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level, vector<Boss*> *boss)
{
	if (!jump)
		velocityY += gravity;
	else
		velocityY = 0;

	x += velocityX;
	y += velocityY;

	int cek;
	cek = 0;


	if (level == 1) {
		if (x > 328 && x < 440 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 1711 && x < 1852 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 2270 && x < 2450 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 2850 && x < 2935 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 3530 && x < 3690 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		// injek pala musuh
		else if (x > 1350 && x < 1450 && y >= 360) {
			if (musuh->at(0)->getValidasi() == true) {
				velocityY = -20;
				y = 360 - 64;

			}
			else if (musuh->at(0)->getValidasi() == false) {
				jump = y + 64 >= 466;
				doublejump = y + 64 >= 466;

			}
			musuh->at(0)->setValidasi(false);
		}

		else {
			//cout << "hush" << endl;
			jump = (y + 64 >= 466);
			doublejump = (y + 64 >= 466);

			if (jump) {
				y = 466 - 64;
				//sound.playJump();
			}

			if (doublejump) {
				y = 466 - 64;
				//sound.playJump();
			}
		}
	}
	else if (level == 2) {
		//ini untuk boss level 2
		if (this->x >= boss->at(0)->getXReal() && this->x <= boss->at(0)->getXReal() + 50 && this->y >= 360) {
			if (boss->at(0)->getValidasi() == true) {
				x -= 130;
				if (getNyawa() > 1)
				{

					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}
				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
			}
			else {
				velocityX = moveSpeed;
			}
			if (cek == 1) {
				menu = true;
				validasi_menu = 2;
				xcu = 0;
			}
		}
		else if (this->x >= boss->at(1)->getXReal() && this->x <= boss->at(1)->getXReal() + 50 && this->y >= 360) {
			if (boss->at(1)->getValidasi() == true) {
				x -= 130;
				if (getNyawa() > 1)
				{

					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}
				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
			}
			else {
				velocityX = moveSpeed;
			}
			if (cek == 1) {
				menu = true;
				validasi_menu = 2;
				xcu = 0;
			}
		}


		if (x > 245 && x < 325 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 465 && x < 535 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 1910 && x < 2080 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		else if (x > 2145 && x < 2270 && y >= 402) {
			y += 15;
			cout << y << endl;
			cout << "jatuh\n";
		}
		
		else if (x > 1350 && x < 1450 && y >= 360) {
			if (musuh->at(0)->getValidasi() == true) {
				velocityY = -20;
				y = 360 - 64;

			}
			else if (musuh->at(0)->getValidasi() == false) {
				jump = y + 64 >= 466;
				doublejump = y + 64 >= 466;

			}
			musuh->at(0)->setValidasi(false);
		}
		else {
			jump = (y + 64 >= 466);
			doublejump = (y + 64 >= 466);

			if (jump) {
				y = 466 - 64;
				//sound.playJump();
			}

			if (doublejump) {
				y = 466 - 64;
				//sound.playJump();
			}
		}
	}

}


int MahasiswaAmbis::getWidth()
{
	return al_get_bitmap_width(image);
}

void MahasiswaAmbis::setSourceX(float x)
{
	MahasiswaAmbis::sourceX = x;
}

void MahasiswaAmbis::setX(float plus)
{
	MahasiswaAmbis::x = plus;
}

void MahasiswaAmbis::setY(float plus)
{
	MahasiswaAmbis::y = plus;
}

void MahasiswaAmbis::addSourceX(float x)
{
	MahasiswaAmbis::sourceX += x;
}

float MahasiswaAmbis::getSourceX()
{
	return MahasiswaAmbis::sourceX;
}

void MahasiswaAmbis::cekGorengan(vector<Gorengan*> *gr, int& level)
{
	if (level == 1) {
		if (this->x > 1490 && this->x < 1520 && this->y> 220 && this->y < 280) {
			cout << "gor1\n";
			if (gr->at(0)->getValidasi() == true)
			{
				if (getCoin() >= 2)
				{
					sound.playEat();
					gr->at(0)->setValidasi(false);
					plusNyawa(1); // +1 nyawa
					minCoin(2); // -2 koin
					cout << "DAPAT NYAWA " << getNyawa() << endl;
					cout << gr->at(0)->getValidasi() << endl;
				}
				else {
					gr->at(0)->setValidasi(true);
					cout << "Koin tidak cukup" << endl;
				}
			}

		}
		else if (this->x > 2890 && this->x < 2920 && this->y> 120 && this->y < 180) {
			cout << "gor2\n";
			if (gr->at(1)->getValidasi() == true) {
				if (getNyawa() < 3 && getCoin() >= 2)
				{
					sound.playEat();
					plusNyawa(1); // +1 nyawa
					minCoin(2); // -2 koin
					gr->at(1)->setValidasi(false);
					cout << "NYAWA " << getNyawa() << endl;
				}
				else {
					gr->at(1)->setValidasi(true);
					cout << "Koin tidak cukup" << endl;
				}
			}
		}
	}
	else if (level == 2)
	{
		if (this->x > 1490 && this->x < 1520 && this->y> 220 && this->y < 280) {
			cout << "gor1\n";
			if (gr->at(0)->getValidasi() == true)
			{
				if (getCoin() >= 2)
				{
					sound.playEat();
					gr->at(0)->setValidasi(false);
					plusNyawa(1); // +1 nyawa
					minCoin(2); // -2 koin
					cout << "DAPAT NYAWA " << getNyawa() << endl;
					cout << gr->at(0)->getValidasi() << endl;
				}
				else {
					gr->at(0)->setValidasi(true);
					cout << "Koin tidak cukup" << endl;
				}
			}

		}
		else if (this->x > 2890 && this->x < 2920 && this->y> 120 && this->y < 180) {
			cout << "gor2\n";
			if (gr->at(1)->getValidasi() == true) {
				if (getNyawa() < 3 && getCoin() >= 2)
				{
					sound.playEat();
					plusNyawa(1); // +1 nyawa
					minCoin(2); // -2 koin
					gr->at(1)->setValidasi(false);
					cout << "NYAWA " << getNyawa() << endl;
				}
				else {
					gr->at(1)->setValidasi(true);
					cout << "Koin tidak cukup" << endl;
				}
			}
		}
		else if (this->x > 3290 && this->x < 3320 && this->y> 270 && this->y < 330) {
			cout << "gor2\n";
			if (gr->at(2)->getValidasi() == true) {
				if (getNyawa() < 3 && getCoin() >= 2)
				{
					sound.playEat();
					plusNyawa(1); // +1 nyawa
					minCoin(2); // -2 koin
					gr->at(2)->setValidasi(false);
					cout << "NYAWA " << getNyawa() << endl;
				}
				else {
					gr->at(2)->setValidasi(true);
					cout << "Koin tidak cukup" << endl;
				}
			}
		}
	}
	else if (this->x > 390 && this->x < 420 && this->y> 1801 && this->y < 240) {
		cout << "gor2\n";
		if (gr->at(3)->getValidasi() == true) {
			if (getNyawa() < 3 && getCoin() >= 2)
			{
				sound.playEat();
				plusNyawa(1); // +1 nyawa
				minCoin(3); // -2 koin
				gr->at(3)->setValidasi(false);
				cout << "NYAWA " << getNyawa() << endl;
			}
			else {
				gr->at(3)->setValidasi(true);
				cout << "Koin tidak cukup" << endl;
			}
		}
	}
}

void MahasiswaAmbis::cekKoin(vector<Koin*> *koin, int& level)
{
	if (level == 1) {
		if (this->x > 1290 && this->x < 1315 && this->y> 270 && this->y < 330) {
			if (koin->at(0)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(0)->setValidasi(false);
		}
		else if (this->x > 1790 && this->x < 1815 && this->y> 270 && this->y < 330) {

			if (koin->at(1)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(1)->setValidasi(false);
		}
		else if (this->x > 3290 && this->x < 3315 && this->y> 270 && this->y < 330) {
			if (koin->at(2)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(2)->setValidasi(false);
		}
		else if (this->x > 390 && this->x < 415 && this->y> 180 && this->y < 240) {
			if (koin->at(3)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(3)->setValidasi(false);
		}
	}
	//untuk lvl 2
	else if (level == 2) {
		if (this->x > 1290 && this->x < 1315 && this->y> 270 && this->y < 330) {
			if (koin->at(0)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(0)->setValidasi(false);
		}
		else if (this->x > 1790 && this->x < 1815 && this->y> 270 && this->y < 330) {
			if (koin->at(1)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(1)->setValidasi(false);
		}
		else if (this->x > 890 && this->x < 915 && this->y> 165 && this->y < 225) {
			if (koin->at(2)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(2)->setValidasi(false);
		}
		else if (this->x > 260 && this->x < 285 && this->y> 190 && this->y < 240) {
			if (koin->at(3)->getValidasi() == true) {
				sound.playCoin();
				plusCoin(1);
				cout << "koin: " << getCoin() << endl;
			}
			koin->at(3)->setValidasi(false);
		}
	}

}

void MahasiswaAmbis::cekBuku(vector<Buku*> *buku, int& level)
{
	if (level == 1) {
		if (this->x > 90 && this->x < 115 && this->y> 270 && this->y < 330) {
			cout << "buku\n";
			if (buku->at(0)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(0)->setValidasi(false);
		}
		else if (this->x > 130 && this->x < 155 && this->y> 270 && this->y < 330) {
			cout << "buku\n";
			if (buku->at(1)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(1)->setValidasi(false);
		}
		else if (this->x > 170 && this->x < 195 && this->y> 270 && this->y < 330) {
			cout << "buku\n";
			if (buku->at(2)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(2)->setValidasi(false);
		}
		else if (this->x > 990 && this->x < 1015 && this->y> 240 && this->y < 300) {
			cout << "buku\n";
			if (buku->at(3)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(3)->setValidasi(false);
		}
		else if (this->x > 1030 && this->x < 1055 && this->y> 240 && this->y < 300) {
			cout << "buku\n";
			if (buku->at(4)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(4)->setValidasi(false);
		}
		else if (this->x > 1070 && this->x < 1095 && this->y> 240 && this->y < 300) {
			cout << "buku\n";
			if (buku->at(5)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(5)->setValidasi(false);
		}
		else if (this->x > 2090 && this->x < 2115 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(6)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(6)->setValidasi(false);
		}
		else if (this->x > 2190 && this->x < 2215 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(7)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(7)->setValidasi(false);
		}
		else if (this->x > 2270 && this->x < 2315 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(8)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(8)->setValidasi(false);
		}
		else if (this->x > 2390 && this->x < 2415 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(9)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(9)->setValidasi(false);
		}
		else if (this->x > 2990 && this->x < 3015 && this->y> 220 && this->y < 280) {
			cout << "buku\n";
			if (buku->at(10)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(10)->setValidasi(false);
		}
		else if (this->x > 3030 && this->x < 3055 && this->y> 220 && this->y < 280) {
			cout << "buku\n";
			if (buku->at(11)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(11)->setValidasi(false);
		}
		else if (this->x > 3070 && this->x < 3095 && this->y> 220 && this->y < 280) {
			cout << "buku\n";
			if (buku->at(12)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(12)->setValidasi(false);
		}
		else if (this->x > 3490 && this->x < 3515 && this->y> 270 && this->y < 330) {
			cout << "buku\n";
			if (buku->at(13)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();
			}
			buku->at(13)->setValidasi(false);
		}
		else if (this->x > 3530 && this->x < 3555 && this->y> 270 && this->y < 330) {
			cout << "buku\n";
			if (buku->at(14)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score" << getScore();

			}
			buku->at(14)->setValidasi(false);
		}
	}
	//untuk lvl 2
	else if (level == 2)
	{
		if (this->x > 90 && this->x < 115 && this->y> 70 && this->y < 265) {
			cout << "buku\n";
			if (buku->at(0)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(0)->setValidasi(false);
		}
		else if (this->x > 135 && this->x < 160 && this->y> 190 && this->y < 250) {
			cout << "buku\n";
			if (buku->at(1)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(1)->setValidasi(false);
		}
		else if (this->x > 175 && this->x < 200 && this->y> 175 && this->y < 235) {
			cout << "buku\n";
			if (buku->at(2)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(2)->setValidasi(false);
		}
		else if (this->x > 990 && this->x < 1015 && this->y> 240 && this->y < 300) {
			cout << "buku\n";
			if (buku->at(3)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(3)->setValidasi(false);
		}
		else if (this->x > 1030 && this->x < 1055 && this->y> 240 && this->y < 300) {
			cout << "buku\n";
			if (buku->at(4)->getValidasi() == true) {
				sound.playBook();
				plusScore(4);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(4)->setValidasi(false);
		}
		else if (this->x > 1070 && this->x < 1095 && this->y> 240 && this->y < 300) {
			cout << "buku\n";
			if (buku->at(4)->getValidasi() == true) {
				sound.playBook();
				plusScore(5);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(5)->setValidasi(false);
		}
		else if (this->x > 1470 && this->x < 1495 && this->y> 130 && this->y < 190) {
			cout << "buku\n";
			if (buku->at(6)->getValidasi() == true) {
				sound.playBook();
				plusScore(5);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(6)->setValidasi(false);
		}
		else if (this->x > 2090 && this->x < 2115 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(7)->getValidasi() == true) {
				sound.playBook();
				plusScore(5);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(7)->setValidasi(false);
		}
		else if (this->x > 2190 && this->x < 2215 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(8)->getValidasi() == true) {
				sound.playBook();
				plusScore(5);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(8)->setValidasi(false);
		}
		else if (this->x > 2290 && this->x < 2310 && this->y> 170 && this->y < 230) {
			cout << "buku\n";
			if (buku->at(9)->getValidasi() == true) {
				sound.playBook();
				plusScore(5);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(9)->setValidasi(false);
		}
		else if (this->x > 1650 && this->x < 1675 && this->y> 70 && this->y < 130) {
			cout << "buku\n";
			if (buku->at(10)->getValidasi() == true) {
				sound.playBook();
				plusScore(5);
				cout << "score: " << getScore() << endl;
				cout << "score total : " << getTotalscore1() << endl;
			}
			buku->at(10)->setValidasi(false);
		}
	}

}

void MahasiswaAmbis::cekMusuh(vector<MahasiswaMusuh*> *musuh, bool& menu, int& validasi_menu, int& xcu, int& level)
{
	if (level == 1) {
		if (this->x > 1350 && this->x < 1435 && this->y> 351 && this->y < 479) {

			if (musuh->at(0)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
				}
				//sound.playCat();
				musuh->at(0)->setValidasi(false);
			}

		}
	}
	else if (level == 2)
	{
		if (this->x > 1340 && this->x < 1405 && this->y> 351 && this->y < 474) {

			if (musuh->at(0)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
				}
				musuh->at(0)->setValidasi(false);
			}

		}
	}
}

void MahasiswaAmbis::cekKucing(vector<Kucing*> *kucing, bool& menu, int& validasi_menu, int& xcu, int& level)
{
	if (level == 1) {
		int cek = 0;
		if (this->x > 468 && this->x < 535 && this->y> 351 && this->y < 479) {
			//else if (this->x > 535 && this->x < 536)
				//x += moveSpeed;
			if (kucing->at(0)->getValidasi() == true) {

				if (getNyawa() > 1)
				{
					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(0)->setValidasi(false);
			}

		}
		else if (this->x > 1070 && this->x < 1140 && this->y> 351 && this->y < 479) {
			if (kucing->at(1)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(1)->setValidasi(false);
			}

		}
		else if (this->x > 1920 && this->x < 1990 && this->y> 351 && this->y < 479) {
			if (kucing->at(2)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(2)->setValidasi(false);
			}

		}
		else if (this->x > 2070 && this->x < 2135 && this->y> 351 && this->y < 479) {
			if (kucing->at(3)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(3)->setValidasi(false);
			}

		}
		else if (this->x > 588 && this->x < 655 && this->y> 338 && this->y < 466) {
			if (kucing->at(4)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(4)->setValidasi(false);
			}

		}
		else {
			kucing->at(0)->setValidasi(true);
			kucing->at(1)->setValidasi(true);
			kucing->at(2)->setValidasi(true);
			kucing->at(3)->setValidasi(true);
			kucing->at(4)->setValidasi(true);
		}

		if (cek == 1) {
			menu = true;
			validasi_menu = 2;
			xcu = 0;
		}
	}


	else if (level == 2)
	{
		int cek = 0;
		if (this->x > 595 && this->x < 660 && this->y> 351 && this->y < 479) {
			if (kucing->at(0)->getValidasi() == true) {

				if (getNyawa() > 1)
				{
					minNyawa(1);
					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(0)->setValidasi(false);
			}

		}
		else if (this->x > 713 && this->x < 785 && this->y> 338 && this->y < 466) {
			if (kucing->at(1)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(1)->setValidasi(false);
			}

		}
		else if (this->x > 868 && this->x < 935 && this->y> 338 && this->y < 466) {
			if (kucing->at(2)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(2)->setValidasi(false);
			}
		}

		else if (this->x > 1550 && this->x < 1620 && this->y> 251 && this->y < 379) {
			if (kucing->at(3)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(3)->setValidasi(false);
			}
		}
		else if (this->x > 1755 && this->x < 1820 && this->y> 338 && this->y < 466) {
			if (kucing->at(4)->getValidasi() == true) {

				if (getNyawa() > 1)
				{

					minNyawa(1);

					cout << "NYAWA: " << getNyawa() << endl;
				}

				else
				{
					cout << "GAMEOVER\n";
					cek = 1;
				}
				sound.playCat();
				kucing->at(4)->setValidasi(false);
			}
		}

		else {
			kucing->at(0)->setValidasi(true);
			kucing->at(1)->setValidasi(true);
			kucing->at(2)->setValidasi(true);
			kucing->at(3)->setValidasi(true);
			kucing->at(4)->setValidasi(true);
		}

		if (cek == 1) {
			menu = true;
			validasi_menu = 2;
			xcu = 0;
		}
		
	}
}


void MahasiswaAmbis::cekFinish(ALLEGRO_EVENT_QUEUE *queue)
{
	bool menu;
	if (MahasiswaAmbis::x > 100) {
		menu = true;
		cout << "Finish\n";
	}
	else {
		menu = false;
	}
	al_destroy_event_queue(queue);
	pg->post_game(menu);
		
}

int MahasiswaAmbis::getNyawa()
{
	return MahasiswaAmbis::nyawa;
}

void MahasiswaAmbis::plusNyawa(int a)
{
	MahasiswaAmbis::nyawa += a;
}

void MahasiswaAmbis::minNyawa(int a)
{
	MahasiswaAmbis::nyawa -= a;
}

float MahasiswaAmbis::getScore()
{
	return  MahasiswaAmbis::score;
}


int MahasiswaAmbis::getCoin()
{
	return koin;
}

void MahasiswaAmbis::minCoin(int c)
{
	koin -= c;
}

void MahasiswaAmbis::plusCoin(int c)
{
	koin += c;
}


void MahasiswaAmbis::plusScore(float b)
{
	MahasiswaAmbis::score += b;
}

void MahasiswaAmbis::totalScore1(float a)
{
	MahasiswaAmbis::totalscorestage1 = MahasiswaAmbis::score / a;

}

float MahasiswaAmbis::getTotalscore1()
{
	return  MahasiswaAmbis::totalscorestage1;
}



MahasiswaAmbis::~MahasiswaAmbis()
{
}

float MahasiswaAmbis::getTotalscore4()
{
	return 0.0f;
}

float MahasiswaAmbis::highscore()
{
	bestscore = getScore() + getCoin( ) + (getNyawa() *2);
	return bestscore;
}

float MahasiswaAmbis::getHighscore()
{
	return bestscore;
}
