#pragma once
class Saveload
{
public:
	Saveload();
	~Saveload();

	void Save(float score);
	void Load();

private:
	
	int score;
	int highscore;
};

