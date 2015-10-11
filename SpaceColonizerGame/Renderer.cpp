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
	GET_LOG.writeToLog("Spawned render thread", "Renderer.cpp", "Renderer()",Utils::Info);
}

Renderer::~Renderer()
{}

void Renderer::updateRenderInfo(std::unique_ptr<Map>& map)
{
	m_map_mutex.lock();
	m_map = std::move(map);
	m_map_mutex.unlock();
}

void Renderer::initRenderer()
{
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
	m_display = al_create_display(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	if (m_display == nullptr)
	{
		auto msg = "Failed to create display!\n";
		fprintf(stderr,"%s\n", msg);
		GET_LOG.writeToLog(msg,"Renderer.cpp","initRenderer",Utils::Critical);
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
		render();
	}
	//since the display was created on the render thread the display must be destroyed on the render thread
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
			GET_LOG.writeToLog("Joined render thread", "Renderer.cpp", "stopRenderer", Utils::Info);
		}
		catch (std::system_error& e)
		{
			GET_LOG.writeToLog(e.what(),"Renderer.cpp","stopRenderer",Utils::Critical);
		}
	//}
}

void Renderer::render()
{
	auto startTime = high_resolution_clock::now();
	al_clear_to_color(BLACK);

	m_cam.update();
	m_zoomLevel = m_cam.getZoomLevel();

	m_map_mutex.lock();
	int screenSizeY = (int)al_get_display_height(m_display);
	int screenSizeX = (int)al_get_display_width(m_display);

	if (m_map != nullptr)
	{
		m_map->loadTextures();
		//al_hold_bitmap_drawing(true);
		m_map->render(m_zoomLevel,screenSizeX,screenSizeY,m_cam.getCameraShift(),m_display);
		//al_hold_bitmap_drawing(false);
	}
	m_map_mutex.unlock();

	auto endTime = high_resolution_clock::now();
	auto renderTime = duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
	al_flip_display();
	float fps = 1000.0f / (float)renderTime;
	if (fps > 60)
	{
		fps = 60;
	}
	//std::cout << "fps: " << fps << std::endl;
	std::cout << "Render Time: " << renderTime << std::endl;
}

