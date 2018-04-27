#include "GameSet.h"



GameSet::GameSet()
{
}


GameSet::~GameSet()
{
}

void GameSet::setValidasiTrue(vector<MahasiswaMusuh*> *musuh, vector<Gorengan*> *gr, vector<Kucing*> *kucing, vector<Buku*> *buku, vector<Koin*> *koin, vector<Boss*> *boss)
{
	int perulangan;
	for (perulangan = 0; perulangan < 15; perulangan++) {
		buku->at(perulangan)->afterGO();
	}
	for (perulangan = 0; perulangan < 2; perulangan++) {
		gr->at(perulangan)->afterGO();
	}
	for (perulangan = 0; perulangan < 2; perulangan++) {
		musuh->at(perulangan)->afterGO();
	}
	for (perulangan = 0; perulangan < 4; perulangan++) {
		koin->at(perulangan)->afterGO();
	}
	for (perulangan = 0; perulangan < 5; perulangan++) {
		kucing->at(perulangan)->afterGO();
	}
	boss->at(0)->afterGO(2500);
	boss->at(1)->afterGO(2700);
}
