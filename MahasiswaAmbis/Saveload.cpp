#include "Saveload.h"
#include "stdafx.h"

Saveload::Saveload()
{
	score = 0;
	highscore = 0;
}


Saveload::~Saveload()
{
}

void Saveload::Save()
{
	cin >> score;
	ofstream writeFile;
	writeFile.open("savedata.txt");
	if (writeFile.is_open()) {
		if (score > highscore) {
			highscore = score;
		}
		writeFile << highscore;
	}
	writeFile.close();
}

void Saveload::Load()
{
	ifstream readFile;
	readFile.open("savedata.txt");
	if (readFile.is_open())
	{

		readFile >> highscore;

	}
	readFile.close();

	cout << "Highscore : " << highscore << endl;
}