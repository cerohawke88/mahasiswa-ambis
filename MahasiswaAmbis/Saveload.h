#pragma once
class Saveload
{
public:
	Saveload();
	~Saveload();

	void Save(float score);
	void Load();
	int getLoad();

private:
	
	int score;
	int highscore;
};

