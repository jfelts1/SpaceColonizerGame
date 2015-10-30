/*
James Felts 2015
*/
#ifndef SPRITEUTILS_H
#define SPRITEUTILS_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include "StringUtils.h"
#include "LogUtils.h"

namespace Utils
{
	extern ALLEGRO_BITMAP* getSprite(std::string filename);
	void cleanSpriteMap();
}

#endif
