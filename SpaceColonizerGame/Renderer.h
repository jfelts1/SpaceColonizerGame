/*
James Felts 2015
*/
#ifndef RENDERER_H
#define RENDERER_H
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
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4265)
#endif
#include <thread>
#include <mutex>
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#include <utility>
#include <functional>
#include <system_error>
#include <iostream>
#include "Utils/LogUtils.h"
#include "GameTile.h"
#include "ColorDefines.h"
#include "Map.h"
#include "Camera.h"
#define SCREEN_SIZE_X 1280
#define SCREEN_SIZE_Y 720
#define GET_RENDERER Renderer::getRenderer()


class Renderer
{
public:
	//copy constructor is deleted
	Renderer(Renderer const&) = delete;
	//copy assignment is deleted
	void operator=(Renderer const&) = delete;
	virtual ~Renderer();
	void updateRenderInfo(std::unique_ptr<Map>& map);
	static Renderer& getRenderer();
	void stopRenderer();
	void render();
private:
	Renderer();

	std::unique_ptr<Map> m_map;
	std::mutex m_map_mutex;

	ALLEGRO_DISPLAY* m_display = nullptr;
	Camera m_cam;

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

