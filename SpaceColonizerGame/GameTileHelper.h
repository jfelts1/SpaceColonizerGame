/*
James Felts 2015
*/
#ifndef GAMETILEHELPER_H
#define GAMETILEHELPER_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <string>
#include "Utils/SpriteUtils.h"
#include "Point.h"
#include "Vector.h"
#define TILE_SPRITE_SIZE 32

class GameTileHelper
{
public:
	GameTileHelper();
	GameTileHelper(const std::string filename) :m_spriteFilename(filename) {}
	//copy constructor
	GameTileHelper(const GameTileHelper& orig)noexcept :m_spriteFilename(orig.m_spriteFilename) 
	{
		m_sprite = orig.m_sprite;
	}
	//copy assignment
	GameTileHelper& operator=(const GameTileHelper& orig) noexcept
	{
		if (this != &orig)
		{
			m_spriteFilename = orig.m_spriteFilename;
			m_sprite = m_sprite;
		}
		return *this;
	}
	//move constructor
	GameTileHelper(GameTileHelper&& orig)noexcept: m_spriteFilename(move(orig.m_spriteFilename))
	{
		m_sprite = m_sprite;
	}
	//move assignment
	GameTileHelper& operator=(GameTileHelper&& orig)noexcept
	{
		if (this != &orig)
		{
			m_spriteFilename = move(orig.m_spriteFilename);
			m_sprite = orig.m_sprite;
		}
		return *this;
	}
	virtual ~GameTileHelper();
	void render(const float x, const float y,const float scale) noexcept;
	void loadTextures()noexcept;
private:
	std::string m_spriteFilename;
	ALLEGRO_BITMAP* m_sprite = nullptr;
};
#endif
