/*
James Felts 2015
*/
#include "GameTileHelper.h"

GameTileHelper::GameTileHelper()
{
}


GameTileHelper::~GameTileHelper()
{
}


void GameTileHelper::render(const float x, const float y, float scale)noexcept
{
	al_draw_scaled_rotated_bitmap(m_sprite, TILE_SPRITE_SIZE, TILE_SPRITE_SIZE, x*scale, y*scale, scale, scale, 0, 0);
}

void GameTileHelper::loadTextures() noexcept
{
	if (m_sprite == nullptr && m_spriteFilename != "")
	{
		m_sprite = Utils::getSprite(m_spriteFilename);
	}
}