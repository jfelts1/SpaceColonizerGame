/*
James Felts 2015
*/
#ifndef STRINGUTILS_H
#define STRINGUTILS_H
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
	int findFirstStringInString(const std::string& str, const std::string& lookFor,const int startAt = 0);
	//returns the substring of the passed in string use instead of substr when determining the count parameter of substr is hard
	//throws game_range_error
	std::string subString(const std::string& str, const int start, const int end);
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
			//int i = 0;
			while (str.size()>0 && isspace((unsigned char)str.front()))
			{
				str.erase(0, 1);
				//i++;
			}
		}
		else
		{
			GET_LOG.writeToLog("Can't trim empty string.","StringUtils.h","ltrim",Utils::Warning);
		}
	}
	//removes whitespace from the end of the given string
	inline void rtrim(std::string& str)
	{
		if (str != "")
		{
			while (str.size()>0 && isspace((unsigned char)str.back()))
			{
				str.pop_back();
			}
		}
		else
		{
			GET_LOG.writeToLog("Can't trim empty string.","StringUtils.h","rtrim",Utils::Warning);
		}
	}
	//removes whitespace from the begining and end of the given string
	inline void trim(std::string& str)
	{
		Utils::ltrim(str);
		Utils::rtrim(str);
	}
	
	//removes everything up to and including the first instance of the given character
	//throws game_invalid_argument
	inline void removeUpToChar(std::string& str,const char ch)
	{
		size_t pos = str.find_first_of(ch, 0);
		if (pos == std::string::npos)
		{
			throw Exceptions::game_invalid_argument("Given character is not in the given string.","StringUtils.h","removeUpToChar");
		}
		else
		{
			str = str.substr(pos + 1);
		}
	}

}

#endif
