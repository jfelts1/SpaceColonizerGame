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
#include "LogUtils.h"

typedef wchar_t wchar;

namespace Utils
{
	//returns the substring nested between two other strings
	std::string getStringBetweenTwoStrings(const std::string& str,const std::string& stringOne,const std::string& stringTwo);
	//finds the first time a string appears in another string
	//returns -1 if nothing is found
	int findFirstStringInString(const std::string& str, const std::string& lookFor,const int startAt = 0);
	//returns the substring of the passed in string use instead of substr when determining the count parameter of substr is hard
	//throws range_error
	std::string subString(const std::string& str, const int start, const int end);
	//returns a vector of strings from an original string split on the given delimitor
	std::vector<std::string> splitString(const std::string& str, const char delim);

	//returns the passed string with whitespace removed from the begining
	inline std::string ltrim(std::string& str)
	{
		if (str != "")
		{
			int i = 0;
			while (str.size()>0 && isspace((unsigned char)str.front()))
			{
				str.erase(i, 1);
				i++;
			}
		}
		else
		{
			GET_LOG.writeToLog("ltrim: can't trim empty string.");
		}
		return str;
	}
	//returns the passed string with whitespace removed from the end
	inline std::string rtrim(std::string& str)
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
			GET_LOG.writeToLog("rtrim: can't trim empty string.");
		}
		return str;
	}
	//returns the passed string with whitespace removed from the begining and end
	inline std::string trim(std::string str)
	{
		Utils::ltrim(str);
		Utils::rtrim(str);
		return str;
	}
	
	//removes everything up to and including the first instance of the given character
	//throws invalid_argument
	inline void removeUpToChar(std::string& str,const char ch)
	{
		size_t pos = str.find_first_of(ch, 0);
		if (pos == std::string::npos)
		{
			throw std::invalid_argument("removeUpToChar: given character is not in the given string.");
		}
		else
		{
			str = str.substr(pos + 1);
		}
	}
}

#endif
