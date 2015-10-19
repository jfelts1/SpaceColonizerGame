/*
James Felts 2015
*/
#include "game_runtime_error.h"

Exceptions::game_runtime_error::game_runtime_error(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : game_exception(msg,throwingFile,throwingFunction)
{
}

Exceptions::game_runtime_error::game_runtime_error(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept : game_exception(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_runtime_error::~game_runtime_error()
{
}
