/*
James Felts 2015
*/
#ifndef GAMETILE_H
#define GAMETILE_H
#include <string>
#include <iostream>
#include "Utils/SpriteUtils.h"
#include "Point.h"
#define TILE_SPRITE_SIZE 10

/*
each tile is 10 by 10
so make each texture file be 10 pixels by 10 pixels
*/

class GameTile
{
public:
	GameTile(float x = 0, float y = 0,const char* filename = "Data/Images/Tiles/RedTile.png");
	virtual ~GameTile();
	void render(float scale);
private:
	std::string m_file;
	ALLEGRO_BITMAP* m_sprite;
	Point m_pos;
};
#endif
