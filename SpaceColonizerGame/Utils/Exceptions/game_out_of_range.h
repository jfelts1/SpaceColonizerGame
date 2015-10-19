/*
James Felts 2015
*/
#ifndef GAME_OUT_OF_RANGE_H
#define GAME_OUT_OF_RANGE_H
#include "game_logic_error.h"
namespace Exceptions
{
	class game_out_of_range :
		public game_logic_error
	{
	public:
		game_out_of_range(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_out_of_range(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_out_of_range();
	};
}
#endif
