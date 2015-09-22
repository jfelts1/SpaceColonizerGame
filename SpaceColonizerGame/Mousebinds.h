/*
James Felts 2015
*/
#ifndef MOUSEBINDS_H
#define MOUSEBINDS_H
#include <allegro5/allegro.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include "Point.h"
#define GET_MOUSEBINDS Mousebinds::getMousebinds()

//singleton class that handles mouse input
class Mousebinds
{
public:
	static Mousebinds& getMousebinds();
	virtual ~Mousebinds() noexcept;
	void shutdownMouseBinds() noexcept;

	Point getMousePos()const noexcept				{ return m_mousePos; }
	
	bool leftMouseClicked() const noexcept			{ return m_mouseLeftClick; }
	bool leftMouseHeld()const noexcept				{ return m_mouseLeftClickHeld; }
	//returns the duration that the left mouse has been held in game ticks
	int leftMouseHeldDuration()const noexcept		{ return m_mouseLeftClickHeldDuration; }
	
	bool rightMouseClicked() const noexcept			{ return m_mouseRightClick; }
	bool rightMouseHeld()const noexcept				{ return m_mouseRightClickHeld; }
	//returns the duration that the right mouse has been held in game ticks
	int rightMouseHeldDuration()const noexcept		{ return m_mouseRightClickHeldDuration; }

	int mouseWheelChange()const noexcept			{ return m_mouseWheelChange; }

	bool scrolledUp() const noexcept;
	bool scrolledDown()const noexcept;
	void update()noexcept;
private:
	Mousebinds();

	ALLEGRO_EVENT_QUEUE* m_events = nullptr;
	ALLEGRO_EVENT_SOURCE* m_mouseEventSource = nullptr;
	ALLEGRO_EVENT m_event;
	ALLEGRO_MOUSE_EVENT m_mouseEvent;
	Point m_mousePos;
	int m_mouseWheel = 0;
	int m_mouseWheelChange = 0;
	
	bool m_mouseLeftClick = false;
	bool m_mouseLeftClickHeld = false;
	int m_mouseLeftClickHeldDuration = 0;

	bool m_mouseRightClick = false;
	bool m_mouseRightClickHeld = false;
	int m_mouseRightClickHeldDuration = 0;
};
#endif
