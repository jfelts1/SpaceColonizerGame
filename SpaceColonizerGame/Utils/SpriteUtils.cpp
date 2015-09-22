/*
James Felts 2015
*/
#include "SpriteUtils.h"

namespace Utils
{
	std::map<std::string, ALLEGRO_BITMAP*> spriteMap;
	std::mutex spriteMap_mutex;

	ALLEGRO_BITMAP * getSprite(std::string filename)
	{
		std::lock_guard<std::mutex> lock(spriteMap_mutex);
		auto search = spriteMap.find(filename);
		//found it
		if (search != spriteMap.end())
		{
			return search->second;
		}
		//need to add to the spritemap
		else
		{
			spriteMap[filename] = al_load_bitmap(filename.c_str());
			if (spriteMap[filename] == NULL)
			{
				std::cerr << "Error loading sprite: " << filename << std::endl;
			}
			return spriteMap[filename];
		}
	}

	void cleanSpriteMap()
	{
		for (auto bit : spriteMap)
		{
			al_destroy_bitmap(bit.second);
		}
	}
}
