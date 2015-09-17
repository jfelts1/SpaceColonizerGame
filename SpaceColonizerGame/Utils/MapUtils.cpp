/*
James Felts 2015
*/
#include "MapUtils.h"

using std::string;
using std::vector;
using std::array;

std::vector<std::vector<GameTile>> Utils::loadMap(const std::string filepath)
{
	vector<vector<GameTile>> ret;
	vector<string> texturePaths;
	vector<string> mapData;
	string rawString;
	string texureDefs;
	string mapDataStr;
	rawString = Utils::readFileAsText(filepath);

	texureDefs = Utils::getStringBetweenTwoStrings(rawString, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS");
	mapDataStr = Utils::getStringBetweenTwoStrings(rawString, "BEGINTEXTUREMAP", "ENDTEXTUREMAP");

	texturePaths = Utils::splitString(texureDefs, ';');
	//remove the number= from the begining of each string
	for (int i = 0;i < (int)texturePaths.size();i++)
	{
		Utils::OddlySpecificUtils::removeNumberEqualsFromBeginingOfString(texturePaths[i]);
	}
	mapData = Utils::splitString(mapDataStr, ';');
	std::istringstream strStream;
	int j;
	for (int i = 0;i < (int)mapData.size();i++)
	{
		j = 0;
		vector<GameTile> tileRow;
		strStream = std::istringstream(mapData[i]);
		while (!strStream.eof())
		{
			int val;
			strStream >> val;
			tileRow.push_back(GameTile(j, i, texturePaths[val].c_str()));
			j++;
		}
		ret.push_back(tileRow);
	}

	return ret;
}


