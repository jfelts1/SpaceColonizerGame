/*
James Felts 2015
*/
#include "Chunk.h"

Chunk::~Chunk()
{
	
}

void Chunk::render(const float scale, Utils::Vector2D vect) const noexcept
{
	for (auto& tile : m_tilesInChunk)
	{
		tile.render(scale,m_pos.x + vect.getX(),m_pos.y+vect.getY());
	}
}
