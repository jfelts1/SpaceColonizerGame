/*
James Felts 2015
*/
#include "Renderer.h"

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::duration;
using std::chrono::duration_cast;

Renderer::Renderer()
{
	m_thread = std::thread(&Renderer::initRenderer, this);
}

Renderer::~Renderer()
{
	m_render = false;
	try
	{
		m_thread.join();
	}
	catch (std::system_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Renderer::updateRenderInfo(std::vector<std::vector<GameTile>> tiles)
{
	std::lock_guard<std::mutex> lock(m_tiles_mutex);
	m_tiles = tiles;
}

void Renderer::initRenderer()
{
	m_display = al_create_display(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	if (m_display == nullptr)
	{
		fprintf(stderr, "failed to create display!\n");
	}
	al_clear_to_color(BLACK);
	m_refreshRate = al_get_display_refresh_rate(m_display);
	m_refreshTime = 1.0 / m_refreshRate;
	startRenderer();
}

void Renderer::startRenderer()
{
	while (m_render)
	{
		for (auto i : m_tiles)
		{
			for (auto tile : i)
			{
				tile.render(m_zoomLevel);
			}
		}
		/*auto startTime = high_resolution_clock::now();

		auto endTime = high_resolution_clock::now();
		auto renderTime = duration_cast<std::chrono::milliseconds>(endTime - startTime).count();*/
		al_flip_display();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
	//since the display was created on the render thread the display must be destroyed on the current thread
	al_destroy_display(m_display);
}

Renderer& Renderer::getRenderer()
{
	static Renderer m_rend;
	return m_rend;
}

