/*
James Felts 2015
*/
#ifndef GAME_INVALID_ARGUMENT_H
#define GAME_INVALID_ARGUMENT_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include "game_logic_error.h"
namespace Exceptions
{
	class game_invalid_argument :
		public game_logic_error
	{
	public:
		game_invalid_argument(const std::string msg, const std::string throwingFile, const std::string throwingFunction)noexcept;
		game_invalid_argument(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_invalid_argument()noexcept;
	};
}
#endif
