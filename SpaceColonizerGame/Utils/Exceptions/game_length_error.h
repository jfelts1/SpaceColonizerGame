/*
James Felts 2015
*/
#ifndef GAME_LENGTH_ERROR_H
#define GAME_LENGTH_ERROR_H
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
