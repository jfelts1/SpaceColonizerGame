/*
James Felts 2015
*/
#ifndef MAP_H
#define MAP_H
#include <memory>
#include <vector>
#include "Chunk.h"
#include "Vector.h"
class Map
{
public:
	Map();
	Map(const std::vector<Chunk> chunks) : m_chunks(chunks) {};
	//copy constructor
	Map(const Map& orig) = delete;
	//copy assignement
	Map& operator=(const Map& orig) = delete;

	//move constructor
	Map(Map&& orig)noexcept: m_chunks(move(orig.m_chunks))
	{}
	//move assignment
	Map& operator=(Map&& orig)
	{
		if (&orig != this)
		{
			m_chunks = move(orig.m_chunks);
		}
		return *this;
	}
	virtual ~Map();

	bool update() noexcept;
	void loadTextures()noexcept;
	void render(const float zoomLevel, const int screenSizeX, const int screenSizeY,const Utils::Vector2D shift,ALLEGRO_DISPLAY* display)noexcept;

	//allows the forcing of creation a copy that can only be owned by one thing
	std::unique_ptr<Map> makeUniqueCopy()const;
private:
	std::vector<Chunk> m_chunks;
};
#endif
