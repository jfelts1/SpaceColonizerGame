/*
James Felts 2015
*/
#ifndef GAME_RANGE_ERROR_H
#define GAME_RANGE_ERROR_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include "game_runtime_error.h"
namespace Exceptions
{
	class game_range_error :
		public game_runtime_error
	{
	public:
		game_range_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_range_error(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_range_error();
	};
}
#endif
