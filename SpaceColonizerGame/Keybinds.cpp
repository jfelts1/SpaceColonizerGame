/*
James Felts 2015
*/
#include "Keybinds.h"

KeyBinds::KeyBinds()
{
	m_events = al_create_event_queue();
	if (m_events == nullptr)
	{
		fprintf(stderr, "failed to create event queue\n");
	}
	m_keyboardEventSource = al_get_keyboard_event_source();
	al_register_event_source(m_events, m_keyboardEventSource);
}

KeyBinds & KeyBinds::getKeyBinds()
{
	static KeyBinds m_keyBinds;
	return m_keyBinds;
}

KeyBinds::~KeyBinds() noexcept
{}

void KeyBinds::shutDownKeyBinds() noexcept
{
	al_unregister_event_source(m_events, m_keyboardEventSource);
	al_destroy_event_queue(m_events);
}

void KeyBinds::update() noexcept
{
	while (!al_is_event_queue_empty(m_events))
	{
		al_get_next_event(m_events, &m_event);
		ALLEGRO_EVENT_TYPE ty = m_event.type;
		//key was pressed
		if (ty == ALLEGRO_EVENT_KEY_DOWN)
		{
			m_keyboardEvent = m_event.keyboard;
			if (m_keyboardEvent.keycode == m_up)
			{
				//m_upHeldMutex.lock();
				m_upHeld = true;
				//m_downHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_down)
			{
				//m_downHeldMutex.lock();
				m_downHeld = true;
				//m_downHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_left)
			{
				//m_leftHeldMutex.lock();
				m_leftHeld = true;
				//m_leftHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_right)
			{
				//m_rightHeldMutex.lock();
				m_rightHeld = true;
				//m_rightHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_quit)
			{
				//m_quitMutex.lock();
				m_quitHeld = true;
				//m_quitMutex.unlock();
			}
		}

		//key was released
		if (ty == ALLEGRO_EVENT_KEY_UP)
		{
			m_keyboardEvent = m_event.keyboard;
			if (m_keyboardEvent.keycode == m_up)
			{
				//m_upHeldMutex.lock();
				m_upHeld = false;
				//m_downHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_down)
			{
				//m_downHeldMutex.lock();
				m_downHeld = false;
				//m_downHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_left)
			{
				//m_leftHeldMutex.lock();
				m_leftHeld = false;
				//m_leftHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_right)
			{
				//m_rightHeldMutex.lock();
				m_rightHeld = false;
				//m_rightHeldMutex.unlock();
			}
			else if (m_keyboardEvent.keycode == m_quit)
			{
				//m_quitMutex.lock();
				m_quitHeld = false;
				//m_quitMutex.unlock();
			}
		}
	}
}
