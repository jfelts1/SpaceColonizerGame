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
	
}

void Renderer::updateRenderInfo(std::unique_ptr<Map>& map,float zoomLevel)
{
	m_map_mutex.lock();
	m_map = std::move(map);
	m_zoomLevel = zoomLevel;
	m_map_mutex.unlock();
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
		al_clear_to_color(BLACK);
		m_map_mutex.lock();
		if (m_map != nullptr)
		{
			m_map->render(m_zoomLevel);
		}
		m_map_mutex.unlock();
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

void Renderer::stopRenderer()
{
	m_render = false;
	//if (m_thread.joinable())
	//{
		try
		{
			m_thread.join();
		}
		catch (std::system_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	//}
}

