/*
James Felts 2015
*/
#include "GameTile.h"
//raw static array for performance reasons
static GameTileHelper m_gameTileHelperAra[MAX_NUMBER_TILE_TEXTURES];
//static short m_usedTileTextures = 0;

GameTile::GameTile(const float x, const float y, const short gameTileSpriteId)
{
	//m_sprite = Utils::getSprite(filename);
	m_pos = Point<float>(x*TILE_SPRITE_SIZE, y*TILE_SPRITE_SIZE);
	//m_spriteFilename = filename;
	m_gameTileSpriteId = gameTileSpriteId;
	//m_terrainFlags = terrainFlags;
}

void GameTile::loadTerainFlags(const std::bitset<TERRAIN_FLAGS_SIZE> terrainFlags)
{
	m_terrainFlags = terrainFlags;
}

GameTile::~GameTile()
{}

void GameTile::render(float scale, const float x, const float y)const noexcept
{
	m_gameTileHelperAra[m_gameTileSpriteId].render(x,y, scale);
}

void GameTile::render(const float scale) const noexcept
{
	m_gameTileHelperAra[m_gameTileSpriteId].render(m_pos.x, m_pos.y, scale);
}

void GameTile::loadTextures() noexcept
{
	for (int i = 0;i <= MAX_NUMBER_TILE_TEXTURES;i++)
	{
		m_gameTileHelperAra[i].loadTextures();
	}
}

void GameTile::loadTileHelper(const std::string filename,const short index) noexcept
{
	/*if (m_usedTileTextures < MAX_NUMBER_TILE_TEXTURES && m_usedTileTextures == index)
	{*/
		m_gameTileHelperAra[index] = GameTileHelper(filename);
		//m_usedTileTextures++;
	//}
}
