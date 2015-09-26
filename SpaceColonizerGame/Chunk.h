/*
James Felts 2015
*/
#ifndef CHUNK_H
#define CHUNK_H
#include <allegro5/allegro.h>
#include <string>
#include <iostream>
#include <thread>
#include <bitset>
#include <cstdint>
#include <array>
#include "Utils/SpriteUtils.h"
#include "GameTile.h"
#include "Point.h"
#include "Vector.h"
#include "GameTileHelper.h"
#define GAMETILES_PER_ROW 32
#define GAMETILES_PER_COL 32
class Chunk
{
public:
	Chunk();
	virtual ~Chunk();
	void createChunkSprite() noexcept;
private:
	std::array<GameTile, GAMETILES_PER_COL*GAMETILES_PER_ROW> m_tilesInChunk;
	//the position of the upper left most tile
	Point<float> m_pos;

	ALLEGRO_BITMAP* m_chunkSprite = nullptr;
};
#endif