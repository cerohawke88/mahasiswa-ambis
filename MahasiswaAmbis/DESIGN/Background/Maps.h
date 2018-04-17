#pragma once
#define BlockSize 32

class Maps
{
public:
	Maps();
	~Maps();
	void loadMap(const char *, vector<vector <int>>&);
	void drawMap(vector<vector<int>>);
private:
	ALLEGRO_BITMAP *road;

};
