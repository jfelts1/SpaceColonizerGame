/*
James Felts 2015
*/
#ifndef GAMETILEHELPER_H
#define GAMETILEHELPER_H
#include <string>
#include "Utils/SpriteUtils.h"
#include "Point.h"
#include "Vector.h"
#define TILE_SPRITE_SIZE 10

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
	GameTileHelper(GameTileHelper&& orig)noexcept: m_spriteFilename(std::move(orig.m_spriteFilename))
	{
		m_sprite = m_sprite;
	}
	//move assignment
	GameTileHelper& operator=(GameTileHelper&& orig)noexcept
	{
		if (this != &orig)
		{
			m_spriteFilename = std::move(orig.m_spriteFilename);
			m_sprite = orig.m_sprite;
		}
		return *this;
	}
	virtual ~GameTileHelper();
	void render(const Point pos,const float scale) noexcept;
	void loadTextures()noexcept;
private:
	std::string m_spriteFilename;
	ALLEGRO_BITMAP* m_sprite = nullptr;
};
#endif
