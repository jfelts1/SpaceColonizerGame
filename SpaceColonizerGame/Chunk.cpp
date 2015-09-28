/*
James Felts 2015
*/
#include "Chunk.h"

Chunk::~Chunk()
{
	if (m_chunkSprite != nullptr)
	{
		al_destroy_bitmap(m_chunkSprite);
	}
}

void Chunk::createChunkSprite() noexcept
{
	m_chunkSprite = al_create_bitmap(DESIRED_TEXTURE_SIZE, DESIRED_TEXTURE_SIZE);
	//fill in the sprite with the gameTiles
}
