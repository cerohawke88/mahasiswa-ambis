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
	MahasiswaAmbis::nyawa = 1;
	MahasiswaAmbis::score = 0;
	MahasiswaAmbis::totalscore1 = 0;
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

void MahasiswaAmbis::maju()
{
	velocityX = moveSpeed;
	this->cekJatuh();
}

void MahasiswaAmbis::mundur()
{
	velocityX = -moveSpeed;
}

void MahasiswaAmbis::cekJatuh()
{
	int x = 0;
	
}

void MahasiswaAmbis::cekLompat()
{
	if (!jump)
		velocityY += gravity;
	else
		velocityY = 0;

	x += velocityX;
	y += velocityY;

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

void MahasiswaAmbis::cekGorengan(vector<Gorengan*> *gr)
{
	if (this->x>1490 && this->x<1510 && this->y> 220 && this->y< 280) {
		cout << "gor1\n";
		if (gr->at(0)->getValidasi() == true)
		{
			if (getNyawa() < 3)
			{

				plusNyawa(1);

				cout << "NYAWA " << getNyawa() << endl;
			}
			sound.playEat();
		}
		gr->at(0)->setValidasi(false);
	} else if (this->x>2890 && this->x<2910 && this->y> 120 && this->y< 180) {
		cout << "gor2\n";
		if (gr->at(1)->getValidasi() == true) {
			sound.playEat();
			if (getNyawa() < 3)
			{

				plusNyawa(1);
				 
				cout <<"NYAWA "<< getNyawa() << endl;
			}
		}
		gr->at(1)->setValidasi(false);
		cout << "gor3\n";
	}
}

void MahasiswaAmbis::cekKoin(vector<Koin*> *koin) 
{
	if (this->x>1290 && this->x<1310 && this->y> 270 && this->y< 330) {
		if (koin->at(0)->getValidasi() == true) {
			//sound.playEat();
		}
		koin->at(0)->setValidasi(false);
	}
	else if (this->x>1790 && this->x<1810 && this->y> 270 && this->y< 330) {
		if (koin->at(1)->getValidasi() == true) {
			//sound.playEat();
		}
		koin->at(1)->setValidasi(false);
	}
	else if (this->x>3290 && this->x<3310 && this->y> 270 && this->y< 330) {
		if (koin->at(2)->getValidasi() == true) {
			//sound.playEat();
		}
		koin->at(2)->setValidasi(false);
	}
	else if (this->x>390 && this->x<410 && this->y> 180 && this->y< 240) {
		if (koin->at(3)->getValidasi() == true) {
			//sound.playEat();
		}
		koin->at(3)->setValidasi(false);
	}

}
void MahasiswaAmbis::cekBuku(vector<Buku*> *buku)
{
	if (this->x>90 && this->x<110 && this->y> 270 && this->y< 330) {
		cout << "buku\n";
		if (buku->at(0)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(0)->setValidasi(false);
	}
	else if (this->x>130 && this->x<150 && this->y> 270 && this->y< 330) {
		cout << "buku\n";
		if (buku->at(1)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(1)->setValidasi(false);
	}
	else if (this->x>170 && this->x<190 && this->y> 270 && this->y< 330) {
		cout << "buku\n";
		if (buku->at(2)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(2)->setValidasi(false);
	}
	else if (this->x>990 && this->x<1010 && this->y> 240 && this->y< 300) {
		cout << "buku\n";
		if (buku->at(3)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(3)->setValidasi(false);
	}
	else if (this->x>1030 && this->x<1050 && this->y> 240 && this->y< 300) {
		cout << "buku\n";
		if (buku->at(4)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(4)->setValidasi(false);
	}
	else if (this->x>1070 && this->x<1090 && this->y> 240 && this->y< 300) {
		cout << "buku\n";
		if (buku->at(5)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(5)->setValidasi(false);
	}
	else if (this->x>2090 && this->x<2110 && this->y> 170 && this->y< 230) {
		cout << "buku\n";
		if (buku->at(6)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(6)->setValidasi(false);
	}
	else if (this->x>2190 && this->x<2210 && this->y> 170 && this->y< 230) {
		cout << "buku\n";
		if (buku->at(7)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(7)->setValidasi(false);
	}
	else if (this->x>2270 && this->x<2310 && this->y> 170 && this->y< 230) {
		cout << "buku\n";
		if (buku->at(8)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(8)->setValidasi(false);
	}
	else if (this->x>2390 && this->x<2410 && this->y> 170 && this->y< 230) {
		cout << "buku\n";
		if (buku->at(9)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(9)->setValidasi(false);
	}
	else if (this->x>2990 && this->x<3010 && this->y> 220 && this->y< 280) {
		cout << "buku\n";
		if (buku->at(10)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(10)->setValidasi(false);
	}
	else if (this->x>3030 && this->x<3050 && this->y> 220 && this->y< 280) {
		cout << "buku\n";
		if (buku->at(11)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(11)->setValidasi(false);
	}
	else if (this->x>3070 && this->x<3090 && this->y> 220 && this->y< 280) {
		cout << "buku\n";
		if (buku->at(12)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(12)->setValidasi(false);
	}
	else if (this->x>3490 && this->x<3510 && this->y> 270 && this->y< 330) {
		cout << "buku\n";
		if (buku->at(13)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(13)->setValidasi(false);
	}
	else if (this->x>3530 && this->x<3550 && this->y> 270 && this->y< 330) {
		cout << "buku\n";
		if (buku->at(14)->getValidasi() == true) {
			//sound.playEat();
			plusScore(4);
			cout << "score" << getScore();
		}
		buku->at(14)->setValidasi(false);
	}
}

void MahasiswaAmbis::cekMusuh(vector<MahasiswaMusuh*> *musuh)
{

}

void MahasiswaAmbis::cekKucing(vector<Kucing*> *kucing) 
{
	if (this->x>468 && this->x<532 && this->y> 351 && this->y< 479) { 
		if (kucing->at(0)->getValidasi() == true) {

			if (getNyawa() > 0)
			{

				minNyawa(1);

				cout << "NYAWA " << getNyawa() << endl;
			}

			else
			{
				cout << "gameover";
			}
			kucing->at(0)->setValidasi(false);
		}
		
	}
	else {
		kucing->at(0)->setValidasi(true);
	}

}

void MahasiswaAmbis::cekFinish(ALLEGRO_EVENT_QUEUE *queue)
{
	bool menu;
	if (MahasiswaAmbis::x > 3954) {
		menu = true;
		cout << "Finish\n";
	}
	else {
		menu = false;
	}
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

int MahasiswaAmbis::getScore()
{
	return  MahasiswaAmbis::score;
}

void MahasiswaAmbis::plusScore(int b)
{
	MahasiswaAmbis::score += b;
}

/*void MahasiswaAmbis::totalScore1()
{
	MahasiswaAmbis::totalscore1 = MahasiswaAmbis::score / 15;
	return  MahasiswaAmbis::totalscore1;
}*/

MahasiswaAmbis::~MahasiswaAmbis()
{
}