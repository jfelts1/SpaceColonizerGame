/*
James Felts 2015
*/
#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <string>
#include <cstring>
#include <cwchar>
#include <cctype>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <vector>
#include <utility>
#include "LogUtils.h"
#include "../GameExceptions.h"

typedef wchar_t wchar;

namespace Utils
{
	//returns the substring nested between two other strings
	//throws game_invalid_argument
	std::string getStringBetweenTwoStrings(const std::string& str,const std::string& stringOne,const std::string& stringTwo);
	//finds the first time a string appears in another string
	//returns -1 if nothing is found
	int findFirstStringInString(const std::string& str, const std::string& lookFor, const size_t startAt = 0);
	//returns the substring of the passed in string use instead of substr when determining the count parameter of substr is hard
	//throws game_range_error
	std::string subString(const std::string& str, const size_t start, const size_t end);
	//returns a vector of strings from the original string split on the given delimitor
	//throws game_invalid_argument
	std::vector<std::string> splitString(const std::string& str, const char delim);
	//returns a string with all the whitespace removed from the given string
	std::string removeAllWhiteSpace(const std::string& str) noexcept;

	//removes whitespace from the begining of the given string
	inline void ltrim(std::string& str)
	{
		if (str != "")
		{
			while (str.size()>0 && isspace(static_cast<unsigned char>(str.front())))
			{
				str.erase(0, 1);
			}
		}
		else
		{
			GET_LOG.writeToLog("Can't trim empty string.","StringUtils.h","ltrim",Warning);
		}
	}
	//removes whitespace from the end of the given string
	inline void rtrim(std::string& str)
	{
		if (str != "")
		{
			while (str.size()>0 && isspace(static_cast<unsigned char>(str.back())))
			{
				str.pop_back();
			}
		}
		else
		{
			GET_LOG.writeToLog("Can't trim empty string.","StringUtils.h","rtrim",Warning);
		}
	}
	//removes whitespace from the begining and end of the given string
	inline void trim(std::string& str)
	{
		ltrim(str);
		rtrim(str);
	}
	
	//removes everything up to and including the first instance of the given character
	//throws game_invalid_argument
	inline void removeUpToChar(std::string& str,const char ch)
	{
		size_t pos = str.find_first_of(ch, 0);
		if (pos != std::string::npos)
		{
			str = str.substr(pos + 1);
		}
		else
		{
			throw Exceptions::game_invalid_argument("Given character is not in the given string.","StringUtils.h","removeUpToChar");
		}
	}

}

#endif
