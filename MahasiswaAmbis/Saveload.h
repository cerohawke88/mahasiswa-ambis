#pragma once
class Saveload
{
public:
	Saveload();
	~Saveload();

private:
	void Save();
	void Load();
	int score;
	int highscore;
};

