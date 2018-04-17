#include "stdafx.h"
#include "Maps.h"

#include "stdafx.h"
#include "maps.h"


Maps::Maps()
{
	road = al_load_bitmap("tile.png");
}


Maps::~Maps()
{
	al_destroy_bitmap(road);
}

void Maps::loadMap(const char *filename, vector<vector <int>> &map) {
	ifstream openfile(filename);
	if (openfile.is_open())
	{
		string line, value;

		while (!openfile.eof())
		{
			getline(openfile, line);
			stringstream str(line);
			vector<int> tempVector;

			while (!str.eof())
			{
				getline(str, value, ' ');
				if (value.length() > 0)
					tempVector.push_back(atoi(value.c_str()));
			}
			map.push_back(tempVector);
		}
	}
}

void Maps::drawMap(vector<vector<int>> map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 1)
				al_draw_bitmap_region(road, 160, 160, 32, 32, j*BlockSize, i*BlockSize, 0);
				//al_draw_filled_rectangle(j * BlockSize, i * BlockSize,	j * BlockSize + BlockSize, i * BlockSize + BlockSize, al_map_rgb(0, 0, 255));

			else
				al_draw_bitmap_region(road, 128, 32, 32, 32, j*BlockSize, i*BlockSize, 0);
				//al_draw_filled_rectangle(j * BlockSize, i * BlockSize,	j * BlockSize + BlockSize, i * BlockSize + BlockSize, al_map_rgb(0, 255, 0));
		}
	}
}