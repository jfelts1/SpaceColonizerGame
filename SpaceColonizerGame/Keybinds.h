/*
James Felts 2015
*/
#ifndef KEYBINDS_H
#define KEYBINDS_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <allegro5/allegro.h>
#include <vector>
#include <iostream>
#include "Utils/LogUtils.h"
#define GET_KEYBINDS KeyBinds::getKeyBinds()

//singleton class that handles keyboard input
class KeyBinds
{
public:
	static KeyBinds& getKeyBinds();
	virtual ~KeyBinds() noexcept;
	void shutDownKeyBinds() noexcept;
	void update() noexcept;

	bool upPressed() const noexcept	{ return m_upHeld; }
	bool leftPressed() const noexcept	{ return m_leftHeld; }
	bool rightPressed() const noexcept { return m_rightHeld; }
	bool downPressed() const noexcept	{ return m_downHeld; }

	bool quitPressed() const noexcept	{ return m_quitHeld; }

private:
	KeyBinds();
	ALLEGRO_EVENT_QUEUE* m_events = nullptr;
	ALLEGRO_EVENT_SOURCE* m_keyboardEventSource = nullptr;
	ALLEGRO_EVENT m_event;
	ALLEGRO_KEYBOARD_EVENT m_keyboardEvent;

	int m_up = ALLEGRO_KEY_W;
	bool m_upHeld = false;
	int m_left = ALLEGRO_KEY_A;
	bool m_leftHeld = false;
	int m_right = ALLEGRO_KEY_D;
	bool m_rightHeld = false;
	int m_down = ALLEGRO_KEY_S;
	bool m_downHeld = false;
	int m_quit = ALLEGRO_KEY_ESCAPE;
	bool m_quitHeld = false;
};

#endif
