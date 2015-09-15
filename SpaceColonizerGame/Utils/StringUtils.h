/*
James Felts 2015
*/
#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <cstring>
#include <iostream>

namespace Utils
{
	//returns the substring nested between two other strings
	std::string getStringBetweenTwoStrings(const std::string rawString,const std::string stringOne,const std::string stringTwo);
	//finds the first time a string appears in another string
	//returns -1 if nothing is found
	int findFirstStringInString(const std::string rawString, const std::string lookFor,const int startAt = 0);
	std::string subString(const std::string rawString, const size_t start, const size_t end);
}

#endif
