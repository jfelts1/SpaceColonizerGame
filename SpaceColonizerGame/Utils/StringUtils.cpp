/*
James Felts 2015
*/
#include "StringUtils.h"

using std::string;
using std::vector;
using std::pair;

std::string Utils::getStringBetweenTwoStrings(const std::string& rawString,const std::string& stringOne,const std::string& stringTwo)
{
	string ret;
	int beg, end;
	beg = Utils::findFirstStringInString(rawString, stringOne);
	if (beg == -1)
	{
		throw Exceptions::game_invalid_argument("stringOne not in the rawString", "StringUtils.cpp", "getStringBetweenTwoStrings");
	}
	end = Utils::findFirstStringInString(rawString, stringTwo,beg);
	if (end == -1)
	{
		throw Exceptions::game_invalid_argument("stringTwo not in the rawString", "StringUtils.cpp", "getStringBetweenTwoStrings");
	}
	ret = Utils::subString(rawString, beg + (int)stringOne.size(), end);
	Utils::trim(ret);

	return ret;
}

int Utils::findFirstStringInString(const std::string& rawString, const std::string& lookFor,int start)
{
	if (lookFor != "")
	{
		int len = (int)lookFor.size();
		const char* rawStr = rawString.c_str();
		const char* lookStr = lookFor.c_str();
		int end = (int)rawString.size();
		for (int i = start;i < end;i++)
		{
			if (strncmp(rawStr + i, lookStr, len)==0)
			{
				return i;
			}
		}
	}
	return -1;
}

std::string Utils::subString(const std::string& str, const int start, const int end)
{
	string ret;
	if (end < start)
	{
		throw Exceptions::game_range_error("Start must be smaller than end","StringUtils.cpp","subString");
	}
	else if (end == start)
	{
		throw Exceptions::game_range_error("Start can't equal end", "StringUtils.cpp", "subString");
	}
	else if (start < 0)
	{
		throw Exceptions::game_range_error("Start must be larger than or equal to 0","StringUtils.cpp","subString");
	}
	else if (end > str.size() || start > str.size())
	{
		throw Exceptions::game_range_error("Start or End can't be past the end of the string", "StringUtils.cpp", "subString");
	}
	for (int i = start;i < end;i++)
	{
		ret.push_back(str[i]);
	}
	return ret;
}

std::vector<std::string> Utils::splitString(const std::string& str, const char delim)
{
	vector<string> ret;

	vector<pair<size_t, size_t>> segmentBegAndEndPos;
	size_t prev = 0;
	size_t delimPos = 0;
	delimPos = str.find_first_of(delim, prev);
	if (delimPos == string::npos)
	{
		throw Exceptions::game_invalid_argument("Given delim is not in the given string.", "StringUtils.cpp", "splitString");
	}
	segmentBegAndEndPos.emplace_back(pair<size_t, size_t>(prev, delimPos));

	while (delimPos != string::npos)
	{
		prev = delimPos;
		delimPos = str.find_first_of(delim, prev+1);
		if (delimPos != string::npos)
		{
			segmentBegAndEndPos.emplace_back(pair<size_t, size_t>(prev+1, delimPos));
		}
	}

	segmentBegAndEndPos.emplace_back(pair<size_t,size_t>(prev + 1, str.size()));
	string tmp;
	for (auto& i : segmentBegAndEndPos)
	{
		tmp = Utils::subString(str, i.first, i.second);
		Utils::trim(tmp);
		ret.emplace_back(tmp);
	}

	return ret;
}

std::string Utils::removeAllWhiteSpace(const std::string & str) noexcept
{
	string ret;
	for (auto& ch : str)
	{
		if (!isspace(ch))
		{
			ret.push_back(ch);
		}
	}
	return ret;
}

