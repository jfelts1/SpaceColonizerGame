/*
James Felts 2015
*/
#ifndef GAME_DOMAIN_ERROR_H
#define GAME_DOMAIN_ERROR_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include "game_logic_error.h"
namespace Exceptions
{
	class game_domain_error :
		public game_logic_error
	{
	public:
		game_domain_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_domain_error(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		virtual ~game_domain_error();
	};
}
#endif
