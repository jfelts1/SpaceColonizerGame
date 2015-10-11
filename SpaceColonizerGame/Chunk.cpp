/*
James Felts 2015
*/
#include "Chunk.h"

Chunk::~Chunk()
{
	destroyChunkSprite();
}

void Chunk::createChunkSprite(ALLEGRO_DISPLAY* display) noexcept
{
	if (m_chunkSprite == nullptr)
	{
		m_chunkSprite = al_create_bitmap(DESIRED_TEXTURE_SIZE, DESIRED_TEXTURE_SIZE);
		al_set_target_bitmap(m_chunkSprite);
		for (auto& tile : m_tilesInChunk)
		{
			tile.render(1);
		}

		//set the render target back to the display before leaving the function
		al_set_target_backbuffer(display);
	}
}

void Chunk::destroyChunkSprite() noexcept
{
	/*if (m_chunkSprite != nullptr)
	{
		al_destroy_bitmap(m_chunkSprite);
	}*/
}

void Chunk::render(const float scale) const noexcept
{
	if (m_chunkSprite != nullptr)
	{
		al_draw_scaled_rotated_bitmap(m_chunkSprite, DESIRED_TEXTURE_SIZE, DESIRED_TEXTURE_SIZE, m_pos.x*scale, m_pos.y*scale, scale, scale, 0, 0);
	}
	else
	{
		GET_LOG.writeToLog("Unable to render chunk, sprite not found","Chunk.cpp","render",Utils::Error);
	}
}
