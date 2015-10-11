/*
James Felts 2015
*/
#include "game_range_error.h"

Exceptions::game_range_error::game_range_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : Exceptions::game_runtime_error(msg,throwingFile,throwingFunction)
{
}

Exceptions::game_range_error::game_range_error(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept : Exceptions::game_runtime_error(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_range_error::~game_range_error()
{
}
