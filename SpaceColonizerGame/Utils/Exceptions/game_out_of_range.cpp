/*
James Felts 2015
*/
#include "game_out_of_range.h"

Exceptions::game_out_of_range::game_out_of_range(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : Exceptions::game_logic_error(msg,throwingFile,throwingFunction)
{
}

Exceptions::game_out_of_range::game_out_of_range(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept : Exceptions::game_logic_error(msg, throwingFile, throwingFunction)
{
}

Exceptions::game_out_of_range::~game_out_of_range()
{
}
