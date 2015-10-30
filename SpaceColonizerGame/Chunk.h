/*
James Felts 2015
*/
#ifndef CHUNK_H
#define CHUNK_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <allegro5/allegro.h>
#include <string>
#include <iostream>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4265)
#endif
#include <thread>
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#include <bitset>
#include <cstdint>
#include <array>
#include "Utils/NumberIsPowerOf2.h"
#include "Utils/SpriteUtils.h"
#include "GameTile.h"
#include "Point.h"
#include "Vector.h"
#include "GameTileHelper.h"
#include "ColorDefines.h"
#define GAMETILES_PER_ROW 32
#define GAMETILES_PER_COL 32
#define DESIRED_TEXTURE_SIZE 1024
typedef std::array<GameTile, GAMETILES_PER_COL*GAMETILES_PER_ROW> chunkData;


class Chunk
{
	static_assert(Utils::numberIsPowerOf2<DESIRED_TEXTURE_SIZE>::value,"DESIRED_TEXTURE_SIZE must be a power of 2.");
	static_assert(DESIRED_TEXTURE_SIZE%TILE_SPRITE_SIZE == 0, "TILE_SPRITE_SIZE must be evenly divisible into DESIRED_TEXTURE_SIZE");
	static_assert(GAMETILES_PER_ROW == GAMETILES_PER_COL, "GAMETILES_PER_ROW and GAMETILES_PER_COL must be equal");
	static_assert(GAMETILES_PER_ROW*GAMETILES_PER_COL == DESIRED_TEXTURE_SIZE, "GAMETILES_PER_ROW*GAMETILES_PER_COL must equal DESIRED_TEXTURE_SIZE");
	static_assert(GAMETILES_PER_ROW > 0 && GAMETILES_PER_COL > 0 && DESIRED_TEXTURE_SIZE > 0 && TILE_SPRITE_SIZE > 0, "Textures can't be of negative size");

public:
	Chunk(const chunkData& chuDat, const Point<float>& pos) :m_tilesInChunk(chuDat), m_pos(pos) {};
	//copy ctor
	Chunk(const Chunk& orig) noexcept 
	{
		m_tilesInChunk = orig.m_tilesInChunk;
		m_pos = orig.m_pos;
	}
	//copy assign
	Chunk& operator=(const Chunk& orig)noexcept
	{
		if (this != &orig)
		{
			m_tilesInChunk = orig.m_tilesInChunk;
			m_pos = orig.m_pos;
		}
		return *this;
	}
	//move ctor
	Chunk(Chunk&& orig)noexcept:m_tilesInChunk(move(orig.m_tilesInChunk)),m_pos(std::move(orig.m_pos))
	{

	}
	//move assign
	Chunk& operator=(Chunk&& orig)noexcept
	{
		if (this != &orig)
		{
			m_tilesInChunk = move(orig.m_tilesInChunk);
			m_pos = std::move(orig.m_pos);
		}
		return *this;
	}
	virtual ~Chunk();
	void render(const float scale, Utils::Vector2D vect)const noexcept;

	float getX()const noexcept { return m_pos.x; }

	float getY()const noexcept { return m_pos.y; }
private:
	chunkData m_tilesInChunk;
	//the position relative to the world
	Point<float> m_pos;

};
#endif
