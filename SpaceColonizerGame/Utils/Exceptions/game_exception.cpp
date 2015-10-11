/*
James Felts 2015
*/
#include "game_exception.h"

Exceptions::game_exception::game_exception(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept : std::exception()
{
	m_msg = msg.c_str();
	m_throwingFile = throwingFile.c_str();
	m_throwingFunction = throwingFunction.c_str();
}

Exceptions::game_exception::game_exception(const char * msg, const char * throwingFile, const char * throwingFunction) noexcept
{
	m_msg = msg;
	m_throwingFile = throwingFile;
	m_throwingFunction = throwingFunction;
}

Exceptions::game_exception::game_exception(const game_exception & other) noexcept
{
	m_msg = other.m_msg;
	m_throwingFile = other.m_throwingFile;
	m_throwingFunction = other.m_throwingFunction;
}

Exceptions::game_exception::~game_exception()
{
}
