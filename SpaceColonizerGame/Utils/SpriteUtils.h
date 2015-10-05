/*
James Felts 2015
*/
#ifndef SPRITEUTILS_H
#define SPRITEUTILS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <set>
#include "StringUtils.h"
#include "LogUtils.h"

namespace Utils
{
	extern ALLEGRO_BITMAP* getSprite(std::string filename);
	void cleanSpriteMap();
}

#endif
