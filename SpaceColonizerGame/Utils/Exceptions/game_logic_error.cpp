/*
James Felts 2015
*/
#include "game_logic_error.h"

Exceptions::game_logic_error::game_logic_error(std::string msg, std::string throwingFile, std::string throwingFunction) noexcept:game_exception(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_logic_error::game_logic_error(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept: game_exception(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_logic_error::~game_logic_error()
{
}
