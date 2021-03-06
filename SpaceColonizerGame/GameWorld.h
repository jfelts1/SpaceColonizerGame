/*
James Felts 2015
*/
#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cstdio>
#include <vector>
#include <memory>
#include <chrono>
#include "Utils/MapUtils.h"
#include "GameTile.h"
#include "Renderer.h"
#include "Map.h"
#include "Camera.h"
#include "Keybinds.h"
#include "Mousebinds.h"

class GameWorld
{
public:
	GameWorld();
	virtual ~GameWorld() noexcept;
	void update() noexcept;

private:
	
	float m_zoomLevel = 1;
	std::shared_ptr<Map> m_map;
	//Camera m_cam;
};
#endif
