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
#include "Utils/NumberIsPowerOf2.h"
#include "Utils/SpriteUtils.h"
#include "GameTile.h"
#include "Point.h"
#include "Vector.h"
#include "GameTileHelper.h"
#define GAMETILES_PER_ROW 32
#define GAMETILES_PER_COL 32
#define DESIRED_TEXTURE_SIZE 1024

/*
 * Use Chunks and A Sieve based on the position of the camera to reduce the number of render calls to around 6 or so
 * */
class Chunk
{
	static_assert(Utils::numberIsPowerOf2<DESIRED_TEXTURE_SIZE>::value,"DESIRED_TEXTURE_SIZE must be a power of 2.");
	static_assert(DESIRED_TEXTURE_SIZE%TILE_SPRITE_SIZE == 0, "TILE_SPRITE_SIZE must be evenly divisible into DESIRED_TEXTURE_SIZE");
	static_assert(GAMETILES_PER_ROW == GAMETILES_PER_COL, "GAMETILES_PER_ROW and GAMETILES_PER_COL must be equal");
	static_assert(GAMETILES_PER_ROW*GAMETILES_PER_COL == DESIRED_TEXTURE_SIZE, "GAMETILES_PER_ROW*GAMETILES_PER_COL must equal DESIRED_TEXTURE_SIZE");
	static_assert(GAMETILES_PER_ROW > 0 && GAMETILES_PER_COL > 0 && DESIRED_TEXTURE_SIZE > 0 && TILE_SPRITE_SIZE > 0, "Textures can't be of negative size");
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
