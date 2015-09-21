/*
James Felts 2015
*/
#include "GameWorld.h"

GameWorld::GameWorld()
{
	m_events = al_create_event_queue();
	if (m_events == nullptr)
	{
		fprintf(stderr, "failed to create event queue\n");
	}
	m_mouseEventSource = al_get_mouse_event_source();

	al_register_event_source(m_events, m_mouseEventSource);


	//init the renderer by calling it's get function
	GET_RENDERER;
	GET_KEYBINDS;
	m_map = Utils::loadMap("Data/Maps/TestMap/TestMap.txt");
}

GameWorld::~GameWorld() noexcept
{
	GET_RENDERER.stopRenderer();
	GET_KEYBINDS.shutDownKeyBinds();
	al_unregister_event_source(m_events, m_mouseEventSource);
	
	al_destroy_event_queue(m_events);
}

void GameWorld::update() noexcept
{
	Utils::Vector vec = m_cam.update();
	m_map->update(vec);
	//create a copy before sending it off to the renderer since the renderer runs on another thread
	std::unique_ptr<Map> copy = m_map->makeUniqueCopy();
	GET_RENDERER.updateRenderInfo(copy,m_zoomLevel);
}


