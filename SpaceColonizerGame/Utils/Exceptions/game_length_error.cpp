/*
James Felts 2015
*/
#include "game_length_error.h"

Exceptions::game_length_error::game_length_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : Exceptions::game_logic_error(msg,throwingFile,throwingFunction)
{
}

Exceptions::game_length_error::game_length_error(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept : Exceptions::game_logic_error(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_length_error::~game_length_error()
{
}
