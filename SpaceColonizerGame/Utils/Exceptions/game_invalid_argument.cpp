/*
James Felts 2015
*/
#include "game_invalid_argument.h"

Exceptions::game_invalid_argument::game_invalid_argument(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : game_logic_error(msg,throwingFile,throwingFunction)
{
}

Exceptions::game_invalid_argument::game_invalid_argument(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept : game_logic_error(msg,throwingFile,throwingFunction)
{
}

Exceptions::game_invalid_argument::~game_invalid_argument() noexcept
{
}
