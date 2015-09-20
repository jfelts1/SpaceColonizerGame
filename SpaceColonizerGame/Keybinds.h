/*
James Felts 2015
*/
#ifndef KEYBINDS_H
#define KEYBINDS_H
#include <allegro5/allegro.h>
#include <vector>
#include <iostream>
#define GET_KEYBINDS KeyBinds::getKeyBinds()

//singleton class that handles keyboard input
class KeyBinds
{
public:
	static KeyBinds& getKeyBinds();
	virtual ~KeyBinds();
	void shutDownKeyBinds();
	void update();
	bool upPressed()const { return m_upHeld; }
	bool leftPressed()const { return m_leftHeld; }
	bool rightPressed()const { return m_rightHeld; }
	bool downPressed()const { return m_downHeld; }
	bool quitPressed()const { return m_quitHeld; }

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
