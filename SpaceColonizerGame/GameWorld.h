/*
James Felts 2015
*/
#ifndef GAMEWORLD_H
#define GAMEWORLD_H
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
#include <thread>
#include "Utils/MapUtils.h"
#include "GameTile.h"
#include "Renderer.h"

class GameWorld
{
public:
	GameWorld();
	virtual ~GameWorld();

private:
	ALLEGRO_EVENT_QUEUE* m_events = nullptr;
	ALLEGRO_EVENT_SOURCE* m_mouseEventSource = nullptr;
	ALLEGRO_EVENT_SOURCE* m_keyboardEventSource = nullptr;
	std::vector<std::vector<GameTile>> m_tiles;
};
#endif
