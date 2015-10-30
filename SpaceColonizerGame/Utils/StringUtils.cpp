/*
James Felts 2015
*/
#include "StringUtils.h"

using std::string;
using std::vector;
using std::pair;

string Utils::getStringBetweenTwoStrings(const string& rawString,const string& stringOne,const string& stringTwo)
{
	string ret;
	int beg, end;
	beg = findFirstStringInString(rawString, stringOne);
	if (beg < 0)
	{
		throw Exceptions::game_invalid_argument("stringOne not in the rawString", "StringUtils.cpp", "getStringBetweenTwoStrings");
	}
	end = findFirstStringInString(rawString, stringTwo,static_cast<size_t>(beg));
	if (end < 0)
	{
		throw Exceptions::game_invalid_argument("stringTwo not in the rawString", "StringUtils.cpp", "getStringBetweenTwoStrings");
	}
	ret = subString(rawString, static_cast<size_t>(beg) + stringOne.size(), static_cast<size_t>(end));
	trim(ret);

	return ret;
}

int Utils::findFirstStringInString(const string& rawString, const string& lookFor, const size_t start)
{
	if (lookFor != "")
	{
		auto len = lookFor.size();
		const char * rawStr = rawString.c_str();
		const char * lookStr = lookFor.c_str();
		auto end = rawString.size();
		for (size_t i = start;i < end;i++)
		{
			if (strncmp(rawStr + i, lookStr, len)==0)
			{
				return static_cast<int>(i);
			}
		}
	}
	return -1;
}

string Utils::subString(const string& str, const size_t start, const size_t end)
{
	string ret;
	if (end < start)
	{
		throw Exceptions::game_range_error("Start must be smaller than end","StringUtils.cpp","subString");
	}
	if (end == start)
	{
		throw Exceptions::game_range_error("Start can't equal end", "StringUtils.cpp", "subString");
	}
	if (static_cast<size_t>(end) > str.size() || static_cast<size_t>(start) > str.size())
	{
		throw Exceptions::game_range_error("Start or End can't be past the end of the string", "StringUtils.cpp", "subString");
	}
	for (auto i = start;i < end;i++)
	{
		ret.push_back(str[i]);
	}
	return ret;
}

vector<string> Utils::splitString(const string& str, const char delim)
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
	//handle the delim being at position 0 by not making a range to substring later
	if (delimPos != 0)
	{
		segmentBegAndEndPos.emplace_back(pair<size_t, size_t>(prev, delimPos));
	}

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
		if (i.first != i.second)
		{
			tmp = subString(str, i.first, i.second);
		}
		trim(tmp);
		ret.emplace_back(tmp);
	}

	return ret;
}

string Utils::removeAllWhiteSpace(const string & str) noexcept
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

