/*
James Felts 2015
*/
#include "MapUtils.h"

using std::string;
using std::vector;
using std::array;

std::shared_ptr<Map> Utils::loadMap(const std::string filepath)
{
	vector<vector<GameTile>> tiles;
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
			std::bitset<TERRAIN_FLAGS_SIZE> tmp = 0;
			GameTile::loadTileHelper(texturePaths[val],val);
			tileRow.push_back(GameTile(j, i, val, tmp));
			j++;
			tileRow.shrink_to_fit();
		}
		tiles.push_back(tileRow);
	}
	tiles.shrink_to_fit();
	return std::make_shared<Map>(tiles);

}


