/*
James Felts 2015
*/
#ifndef GAME_RANGE_ERROR_H
#define GAME_RANGE_ERROR_H
#include "game_runtime_error.h"
namespace Exceptions
{
	class game_range_error :
		public Exceptions::game_runtime_error
	{
	public:
		game_range_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_range_error(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_range_error();
	};
}
#endif
