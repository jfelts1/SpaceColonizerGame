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
	vector<array<vector<GameTile>, GAMETILES_PER_COL>> tempArrays;
	vector<array<array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW>> chunkTempData;
	vector<Chunk> chunks;
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
		//size_t widthOfMap = (mapData[i].size() - 1) / 2;
		vector<GameTile> tileRow;
		strStream = std::istringstream(mapData[i]);
		while (!strStream.eof())
		{
			int val;
			strStream >> val;
			std::bitset<TERRAIN_FLAGS_SIZE> tmp = 0;
			GameTile::loadTileHelper(texturePaths[val],val);
			tileRow.emplace_back(GameTile(j, i, val, tmp));
			j++;
		}
		tiles.push_back(tileRow);
	}

	vector<vector<GameTile>> tmp;
	for (size_t i = 0;i < tiles.size();i++)
	{
		if (i%GAMETILES_PER_COL == 0 && i >0)
		{
			tempArrays.emplace_back(Utils::SpecicalMapUtils::getRowDataPerChunk(tmp));
		}
		tmp.emplace_back(tiles[i]);
		if (i == tiles.size() - 1)
		{
			tempArrays.emplace_back(Utils::SpecicalMapUtils::getRowDataPerChunk(tmp));
		}
	}
	for (auto& rowsOfChunck : tempArrays)
	{
		chunkTempData = Utils::SpecicalMapUtils::getChunkData(rowsOfChunck);
		for (auto& chunk : chunkTempData)
		{
			chunks.emplace_back(chunk);
		}
	}

	chunks.shrink_to_fit();

	//return std::make_shared<Map>(tiles);

}

std::array<std::vector<GameTile>, GAMETILES_PER_COL> Utils::SpecicalMapUtils::getRowDataPerChunk(const std::vector<std::vector<GameTile>> tiles)
{
	array<vector<GameTile>, GAMETILES_PER_COL> ret;
	for (size_t i = 0;i < tiles.size();i++)
	{
		ret[i] = tiles[i];
	}
	return ret;
}

std::vector<array<array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW>> Utils::SpecicalMapUtils::getChunkData(const std::array<std::vector<GameTile>, GAMETILES_PER_COL> rowDataPerChunk)
{
	vector<array<array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW>> ret;
	std::array<std::vector<GameTile>, GAMETILES_PER_COL> remainingRowDataPerChunk;
	size_t chunkNum = 0;
	

	return ret;
}

std::array<std::array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW> Utils::SpecicalMapUtils::getChunk(const std::array<std::vector<GameTile>, GAMETILES_PER_COL> rowDataPerChunk)
{
	array<array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW> ret;
	size_t i = 0;
	for (auto& row : rowDataPerChunk)
	{
		for (size_t j = 0;j < row.size()&&j<GAMETILES_PER_ROW;j++)
		{
			ret[j][i] = row[j];
		}
		i++;
	}
	return ret;
}
