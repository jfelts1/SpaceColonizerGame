/*
James Felts 2015
*/
#include "StringUtils.h"

using std::string;

std::string Utils::getStringBetweenTwoStrings(const std::string& rawString,const std::string& stringOne,const std::string& stringTwo)
{
	string ret;
	int beg, end;
	beg = Utils::findFirstStringInString(rawString, stringOne);
	end = Utils::findFirstStringInString(rawString, stringTwo,beg);
	//std::cout << beg << " " << end << std::endl;
	//using subString instead of substr since substr's count paramenter would need need to vary when near the end of rawString in a way that would be annoying
	ret = Utils::subString(rawString, beg + (int)stringOne.size(), end);
	//std::cout << ret << std::endl;

	return ret;
}

int Utils::findFirstStringInString(const std::string& rawString, const std::string& lookFor,int start)
{
	int len = (int)lookFor.size();
	const char* rawStr = rawString.c_str();
	const char* lookStr = lookFor.c_str();
	int end = (int)rawString.size();
	for (int i = start;i < end;i++)
	{
		//taking advantage of pointer math to search through the string
		if (strncmp(rawStr + i, lookStr, len)==0)
		{
			return i;
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
		throw Exceptions::game_range_error("Start must be larger than 0","StringUtils.cpp","subString");
	}
	for (int i = start;i < end;i++)
	{
		ret.push_back(str[i]);
	}
	return ret;
}

std::vector<std::string> Utils::splitString(const std::string& str, const char delim)
{
	std::vector<string> ret;
	//-1 makes the code simpler
	int prev = -1;
	size_t delimPos = 0;
	delimPos = str.find_first_of(delim, 0);
	string tmp;
	while (delimPos != std::string::npos)
	{
		tmp = Utils::trim(str.substr(prev+1, delimPos-(prev+1)));
		if (tmp != "")
		{
			ret.push_back(tmp);
		}
		prev = (int)delimPos;
		delimPos = (int)str.find_first_of(delim, prev + 1);
	}

	return ret;
}

