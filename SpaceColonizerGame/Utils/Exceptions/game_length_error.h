/*
James Felts 2015
*/
#ifndef GAME_LENGTH_ERROR_H
#define GAME_LENGTH_ERROR_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include "game_logic_error.h"
namespace Exceptions
{
	class game_length_error :
		public game_logic_error
	{
	public:
		game_length_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_length_error(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_length_error();
	};
}
#endif
