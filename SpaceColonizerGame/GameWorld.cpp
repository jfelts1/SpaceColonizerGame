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
	m_keyboardEventSource = al_get_keyboard_event_source();
	al_register_event_source(m_events, m_mouseEventSource);
	al_register_event_source(m_events, m_keyboardEventSource);

	m_tiles = Utils::loadMap("Data/Maps/TestMap/TestMap.txt");
	Renderer::getRenderer().updateRenderInfo(m_tiles);
}

GameWorld::~GameWorld()
{
	//Renderer::getRenderer().~Renderer();
	Renderer::getRenderer().stopRenderer();
	al_unregister_event_source(m_events, m_mouseEventSource);
	al_unregister_event_source(m_events, m_keyboardEventSource);
	al_destroy_event_queue(m_events);
}


