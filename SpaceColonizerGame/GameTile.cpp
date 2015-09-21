/*
James Felts 2015
*/
#include "GameTile.h"

GameTile::GameTile(float x, float y,const char* filename)
{
	m_sprite = Utils::getSprite(filename);
	m_pos = Point(x*TILE_SPRITE_SIZE, y*TILE_SPRITE_SIZE);
}

GameTile::~GameTile()
{
}

void GameTile::render(float scale)const noexcept
{
	//std::cout << m_file << std::endl;
	al_draw_scaled_rotated_bitmap(m_sprite, TILE_SPRITE_SIZE, TILE_SPRITE_SIZE, m_pos.x*scale, m_pos.y*scale, scale, scale, 0, 0);
}

