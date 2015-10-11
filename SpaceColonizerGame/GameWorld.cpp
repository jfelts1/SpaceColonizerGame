/*
James Felts 2015
*/
#include "GameWorld.h"

GameWorld::GameWorld()
{
	//init the renderer by calling it's get function
	GET_RENDERER;
	GET_KEYBINDS;
	GET_MOUSEBINDS;
	m_map = Utils::loadMap("Data/Maps/TestMap/TestMap.gamemap");
	GET_LOG.writeToLog("Done loading Map", "GameWorld.cpp", "GameWorld()", Utils::Info);
	std::unique_ptr<Map> copy = m_map->makeUniqueCopy();
	GET_RENDERER.updateRenderInfo(copy);
}

GameWorld::~GameWorld() noexcept
{
	GET_RENDERER.stopRenderer();
	GET_KEYBINDS.shutDownKeyBinds();
	GET_MOUSEBINDS.shutdownMouseBinds();
	
}

void GameWorld::update() noexcept
{
	bool mapUpdated = m_map->update();
	//only send new map info to the renderer if the map has changed
	if (mapUpdated)
	{
		//create a copy before sending it off to the renderer since the renderer runs on another thread
		std::unique_ptr<Map> copy = m_map->makeUniqueCopy();
		GET_RENDERER.updateRenderInfo(copy);
	}
}


