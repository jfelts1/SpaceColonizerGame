/*
James Felts 2015
*/
#ifndef RENDERER_H
#define RENDERER_H
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
#include <mutex>
#include <utility>
#include <functional>
#include <system_error>
#include <iostream>
#include "GameTile.h"
#include "ColorDefines.h"
#define SCREEN_SIZE_X 1280
#define SCREEN_SIZE_Y 720

class Renderer
{
public:
	//copy constructor is deleted
	Renderer(Renderer const&) = delete;
	//copy assignment is deleted
	void operator=(Renderer const&) = delete;
	virtual ~Renderer();
	void updateRenderInfo(std::vector<std::vector<GameTile>> tiles);
	static Renderer& getRenderer();
	void stopRenderer();
private:
	Renderer();

	std::vector<std::vector<GameTile>> m_tiles;
	std::mutex m_tiles_mutex;

	ALLEGRO_DISPLAY* m_display = nullptr;

	std::thread m_thread;
	//used to tell the render thread whether it should keep looping
	bool m_render = true;

	int m_refreshRate;
	double m_refreshTime;

	float m_zoomLevel = 1;

	void initRenderer();

	void startRenderer();
};


#endif

