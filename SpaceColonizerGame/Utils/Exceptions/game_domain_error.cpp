/*
James Felts 2015
*/
#include "game_domain_error.h"

Exceptions::game_domain_error::game_domain_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : game_logic_error(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_domain_error::game_domain_error(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept : game_logic_error(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_domain_error::~game_domain_error()
{
}
