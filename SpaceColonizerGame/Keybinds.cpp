/*
James Felts 2015
*/
#include "Keybinds.h"

KeyBinds::KeyBinds()
{
	m_events = al_create_event_queue();
	if (m_events == nullptr)
	{
		auto msg = "Keybinds.cpp:Keybinds(): Failed to create event queue\n";
		fprintf(stderr,"%s\n", msg);
		GET_LOG.writeToLog(msg,"Keybinds.cpp","KeyBinds()",Utils::Critical);
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
				m_upHeld = true;
			}
			else if (m_keyboardEvent.keycode == m_down)
			{
				m_downHeld = true;
			}
			else if (m_keyboardEvent.keycode == m_left)
			{
				m_leftHeld = true;
			}
			else if (m_keyboardEvent.keycode == m_right)
			{
				m_rightHeld = true;
			}
			else if (m_keyboardEvent.keycode == m_quit)
			{
				m_quitHeld = true;
			}
		}

		//key was released
		if (ty == ALLEGRO_EVENT_KEY_UP)
		{
			m_keyboardEvent = m_event.keyboard;
			if (m_keyboardEvent.keycode == m_up)
			{
				m_upHeld = false;
			}
			else if (m_keyboardEvent.keycode == m_down)
			{
				m_downHeld = false;
			}
			else if (m_keyboardEvent.keycode == m_left)
			{
				m_leftHeld = false;
			}
			else if (m_keyboardEvent.keycode == m_right)
			{
				m_rightHeld = false;
			}
			else if (m_keyboardEvent.keycode == m_quit)
			{
				m_quitHeld = false;
			}
		}
	}
}
