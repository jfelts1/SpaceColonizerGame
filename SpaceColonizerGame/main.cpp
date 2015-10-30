/*
James Felts 2015
*/
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <cstdlib>
#include <cstdio>
#include <allegro5/allegro.h>
#include "ColorDefines.h"
#include "GameWorld.h"
#define MS_PER_TICK 16

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::duration;
using std::chrono::duration_cast;

bool initGameLibraries();
void shutdownGameLibraries();

//turn off warning for unused params for main
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4100)
#endif
int main(int argc, char **argv)
{
	//call GET_LOG to init the logging system
	GET_LOG;
	auto success = initGameLibraries();
	if (success)
	{
		//using new and delete since relying on scoping to delete things causes the clean up of the GameWorld to happen after allegro has shutdown
		//causing access violations
		auto world =  new GameWorld();
		while (GET_KEYBINDS.quitPressed() == false)
		{
			auto startTime = high_resolution_clock::now();
			GET_KEYBINDS.update();
			GET_MOUSEBINDS.update();
			world->update();
			auto endTime = high_resolution_clock::now();
			auto gameTickTime = duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
			std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_TICK - gameTickTime));
			//std::cout << "Game Tick Time" << gameTickTime << std::endl;
		}
		
		delete world;
		shutdownGameLibraries();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif

bool initGameLibraries()
{
	if (!al_init())
	{
		auto msg = "failed to initialize allegro!\n";
		fprintf(stderr,"%s\n", msg);
		GET_LOG.writeToLog(msg,"main.cpp","initGameLibraries",Utils::Critical);
		return false;
	}

	if (!al_init_image_addon())
	{
		auto msg = "failed to initialize allegro image addon!\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	if (!al_init_primitives_addon())
	{
		auto msg = "failed to initialize allegro primitives addon!\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	if (!al_install_audio())
	{
		auto msg = "failed to install audio system\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	if (!al_init_acodec_addon())
	{
		auto msg = "failed to init audio codec system\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	if (!al_reserve_samples(25))
	{
		auto msg = "failed to reserve audio samples\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	if (!al_install_mouse())
	{
		auto msg = "no mouse found!\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	if (!al_install_keyboard())
	{
		auto msg = "no keyboard found!\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}
	al_init_font_addon();
	if (!al_init_ttf_addon())
	{
		auto msg = "unable to init ttf fonts\n";
		fprintf(stderr, "%s\n", msg);
		GET_LOG.writeToLog(msg, "main.cpp", "initGameLibraries", Utils::Critical);
		return false;
	}

	return true;
}

void shutdownGameLibraries()
{
	Utils::cleanSpriteMap();

	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_uninstall_audio();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_uninstall_system();
}
