/*
James Felts 2015
*/
#ifndef GAME_LOGIC_ERROR_H
#define GAME_LOGIC_ERROR_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <stdexcept>
#include <string>
#include "game_exception.h"
namespace Exceptions
{
	class game_logic_error :
		public game_exception
	{
	public:
		game_logic_error(std::string msg, std::string throwingFile, std::string throwingFunction)noexcept;
		game_logic_error(const char* msg, const char* throwingFile, const char* throwingFunction)noexcept;
		virtual ~game_logic_error();
	};
}
#endif
