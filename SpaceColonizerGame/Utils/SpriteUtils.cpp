/*
James Felts 2015
*/
#include "SpriteUtils.h"

namespace Utils
{
	std::map<std::string, ALLEGRO_BITMAP*> spriteMap;
	std::mutex spriteMap_mutex;

	ALLEGRO_BITMAP * getSprite(const char * filename)
	{
		std::lock_guard<std::mutex> lock(spriteMap_mutex);
		auto search = spriteMap.find(filename);
		//std::cout << "found " << spriteMap.count(filename) << " " << filename << std::endl;
		//found it
		if (search != spriteMap.end())
		{
			return search->second;
		}
		//need to add to the spritemap
		else
		{
			std::pair<const char*, ALLEGRO_BITMAP*> tmp = { filename,al_load_bitmap(filename) };
			//spriteMap[filename] = al_load_bitmap(filename);
			spriteMap.insert(tmp);
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
