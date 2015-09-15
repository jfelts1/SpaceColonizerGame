/*
James Felts 2015
*/
#include "StringUtils.h"

using std::string;

std::string Utils::getStringBetweenTwoStrings(const std::string rawString,const std::string stringOne,const std::string stringTwo)
{
	string ret;
	int beg, end;
	beg = Utils::findFirstStringInString(rawString, stringOne);
	end = Utils::findFirstStringInString(rawString, stringTwo,beg);
	//std::cout << beg << " " << end << std::endl;
	ret = Utils::subString(rawString, beg + stringOne.size(), end);
	std::cout << ret << std::endl;

	return ret;
}

int Utils::findFirstStringInString(const std::string rawString, const std::string lookFor,int startAt)
{
	int len = (int)lookFor.size();
	const char* rawStr = rawString.c_str();
	const char* lookStr = lookFor.c_str();
	for (int i = startAt;i < rawString.size();i++)
	{
		if (strncmp(rawStr + i, lookStr, len)==0)
		{
			return i;
		}
	}

	return -1;
}

std::string Utils::subString(const std::string rawString, const size_t start, const size_t end)
{
	string ret;
	for (size_t i = start;i < end;i++)
	{
		ret.push_back(rawString[i]);
	}

	return ret;
}
