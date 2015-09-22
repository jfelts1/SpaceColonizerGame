/*
James Felts 2015
*/
#include "Mousebinds.h"

Mousebinds::Mousebinds()
{
	m_events = al_create_event_queue();
	if (m_events == nullptr)
	{
		fprintf(stderr, "failed to create event queue\n");
	}
	m_mouseEventSource = al_get_mouse_event_source();

	al_register_event_source(m_events, m_mouseEventSource);
}


Mousebinds& Mousebinds::getMousebinds()
{
	static Mousebinds m_mouseBinds;
	return m_mouseBinds;
}

Mousebinds::~Mousebinds() noexcept
{}

void Mousebinds::shutdownMouseBinds() noexcept
{
	al_unregister_event_source(m_events, m_mouseEventSource);
	al_destroy_event_queue(m_events);
}

bool Mousebinds::scrolledUp() const noexcept
{
	if (m_mouseWheelChange > 0)
	{
		return true;
	}
	return false;
}

bool Mousebinds::scrolledDown() const noexcept
{
	if (m_mouseWheelChange < 0)
	{
		return true;
	}
	return false;
}

void Mousebinds::update() noexcept
{
	m_mouseLeftClick = false;
	m_mouseRightClick = false;
	m_mouseWheelChange = 0;
	if (leftMouseHeld())
	{
		m_mouseLeftClickHeldDuration++;
	}
	if (rightMouseHeld())
	{
		m_mouseRightClickHeldDuration++;
	}
	while (!al_is_event_queue_empty(m_events))
	{
		al_get_next_event(m_events, &m_event);
		ALLEGRO_EVENT_TYPE ty = m_event.type;
		if (ty == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			m_mouseEvent = m_event.mouse;
			//left mouse button
			if (m_mouseEvent.button & 1)
			{
				m_mouseLeftClick = true;
				m_mouseLeftClickHeld = true;
				m_mouseLeftClickHeldDuration = 0;
				//printf("left mouse click at x: %d y: %d\n", m_mouseEvent.x, m_mouseEvent.y);
			}
			//right mouse button
			else if (m_mouseEvent.button & 2)
			{
				m_mouseRightClick = true;
				m_mouseRightClickHeld = true;
				m_mouseRightClickHeldDuration = 0;
				//printf("right mouse click at x: %d y: %d\n", m_mouseEvent.x, m_mouseEvent.y);
			}
		}
		if (ty == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			m_mouseEvent = m_event.mouse;
			//left mouse button
			if (m_mouseEvent.button & 1)
			{
				m_mouseLeftClick = false;
				m_mouseLeftClickHeld = false;
				m_mouseLeftClickHeldDuration = 0;
				//printf("left mouse click at x: %d y: %d\n", m_mouseEvent.x, m_mouseEvent.y);
			}
			//right mouse button
			else if (m_mouseEvent.button & 2)
			{
				m_mouseRightClick = false;
				m_mouseRightClickHeld = false;
				m_mouseRightClickHeldDuration = 0;
				//printf("right mouse click at x: %d y: %d\n", m_mouseEvent.x, m_mouseEvent.y);
			}
		}

		//mouse was moved
		if (ty == ALLEGRO_EVENT_MOUSE_AXES)
		{
			m_mouseEvent = m_event.mouse;
			m_mousePos.x = m_mouseEvent.x;
			m_mousePos.y = m_mouseEvent.y;
			m_mouseWheel = m_mouseEvent.z;
			m_mouseWheelChange = m_mouseEvent.dz;
			//printf("mouse at x: %d y: %d\n", mouseEvent.x, mouseEvent.y);
		}
	}
}


