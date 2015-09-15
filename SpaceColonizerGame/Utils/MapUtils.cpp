/*
James Felts 2015
*/
#include "MapUtils.h"

using std::string;
using std::vector;

std::vector<std::vector<GameTile>> Utils::loadMap(const std::string filepath)
{
	vector<vector<GameTile>> ret;
	vector<string> texturePaths;
	string rawString;
	string texureDefs;
	string mapData;
	rawString = Utils::readFileAsText(filepath);

	texureDefs = Utils::getStringBetweenTwoStrings(rawString, "BEGINTEXTUREDEFS\n", "ENDTEXTUREDEFS\n");
	mapData = Utils::getStringBetweenTwoStrings(rawString, "BEGINTEXTUREMAP\n", "ENDTEXTUREMAP\n");


	return ret;
}
