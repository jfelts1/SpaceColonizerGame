/*
James Felts 2015
*/
#ifndef GAME_RUNTIME_ERROR_H
#define GAME_RUNTIME_ERROR_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include "game_exception.h"
namespace Exceptions
{
	class game_runtime_error :
		public game_exception
	{
	public:
		game_runtime_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_runtime_error(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_runtime_error();
	};
}
#endif
