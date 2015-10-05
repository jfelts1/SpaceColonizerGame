/*
James Felts 2015
*/
#include "MapUtils.h"

using std::string;
using std::vector;
using std::array;
using std::istringstream;

std::unique_ptr<Map> Utils::loadMap(const std::string filepath)
{
	vector<Chunk> chunks;
	texturePathsDefs texturePaths;
	chunkDataStrings mapData;
	terrainGameTileFlags terrainFlags;

	string rawString;
	string texureDefs;
	string mapDataStr;
	string terrainFlagsStr;
	rawString = Utils::readFileAsText(filepath);

	texureDefs = Utils::getStringBetweenTwoStrings(rawString, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS");
	mapDataStr = Utils::getStringBetweenTwoStrings(rawString, "BEGINCHUNKTEXDATA", "ENDCHUNKTEXDATA");

	//handle texure definitions
	textureDefsStrings texturePathsTmp = Utils::splitString(texureDefs, ';');
	texturePaths = Utils::SpecicalMapUtils::getTexturePathArray(texturePathsTmp);
	texturePathsTmp.clear();

	//handle terrainFlags
	chunkTerrainFlagsStrings chuTerFlgsStrs = Utils::SpecicalMapUtils::getTerrainFlagsStrings(terrainFlagsStr);
	terrainFlags = Utils::SpecicalMapUtils::getTerrainFlags(chuTerFlgsStrs);
	chuTerFlgsStrs.clear();

	//handle chunks
	mapData = Utils::splitString(mapDataStr, 'P');
	chunks = Utils::SpecicalMapUtils::getChunks(mapData,texturePaths,terrainFlags);
	chunks.shrink_to_fit();

	return std::make_unique<Map>(chunks);
}

Utils::texturePathsDefs Utils::SpecicalMapUtils::getTexturePathArray(const textureDefsStrings& texDefsStrs)
{
	texturePathsDefs ret;
	short textureIndex;
	istringstream texStrStream;
	try
	{
		for (auto texPath : texDefsStrs)
		{
			textureIndex = -1;
			texStrStream = istringstream(texPath);
			texStrStream >> textureIndex;
			if (textureIndex < 0 || textureIndex>MAX_NUMBER_TILE_TEXTURES - 1)
			{
				throw std::out_of_range("MapUtils.cpp getTexturePathArray: the number attached to the texure is out of range.");
			}
			Utils::removeUpToChar(texPath, '=');
			ret[textureIndex] = std::move(texPath);
		}
	}
	catch (std::invalid_argument& e)
	{
		GET_LOG.writeToLog(e.what());
	}
	catch (std::out_of_range& e)
	{
		GET_LOG.writeToLog(e.what());
	}
	return ret;
}

std::vector<Chunk> Utils::SpecicalMapUtils::getChunks(const chunkDataStrings& chuDatStr, const texturePathsDefs& texPathDefs, const terrainGameTileFlags& chuTerFlgs)
{
	vector<Chunk> ret;
	istringstream chunkStrStream;
	vector<string> tmp;
	chunkData chuDat;
	GameTile temp;
	float x, y;
	int val;
	int chunkIndex = 0;
	try
	{
		for (int j = 0;j < chuDatStr.size();j++)
		{
			chunkIndex = 0;
			//break the chunk string into 33 rows a position and 32 data rows
			tmp = Utils::splitString(chuDatStr[j], ';');
			//get the position data
			chunkStrStream = istringstream(tmp[0]);
			chunkStrStream >> x;
			chunkStrStream >> y;
			//read the chunk data
			for (int i = 1;i < tmp.size();i++)
			{
				val = 0;
				chunkStrStream = istringstream(tmp[i]);
				//read each chunk row one tile at a time
				while (!chunkStrStream.eof())
				{
					chunkStrStream >> val;
					if (val <0 || val > MAX_NUMBER_TILE_TEXTURES - 1)
					{
						throw std::out_of_range("MapUtils.cpp getChunks: the number to look up the texture is out of range.");
					}
					//load the texture into the tileHelper array
					GameTile::loadTileHelper(texPathDefs[val], val);
					chuDat[chunkIndex] = GameTile(chunkIndex%GAMETILES_PER_ROW, chunkIndex / GAMETILES_PER_COL, val);
					chunkIndex++;
				}
			}
			//set the terrain flags for each tile of the chunk
			/*for (int i = 0;i < MAX_NUMBER_TILE_TEXTURES;i++)
			{
				chuDat[i].loadTerainFlags(chuTerFlgs[j][i]);
			}*/
			ret.emplace_back(Chunk(chuDat, Point<float>(x*DESIRED_TEXTURE_SIZE, y*DESIRED_TEXTURE_SIZE)));
		}
	}
	catch (std::out_of_range& e)
	{
		GET_LOG.writeToLog(e.what());
	}

	return ret;
}

//placeholder stubs since the actualy flags aren't part of the map format yet
Utils::chunkTerrainFlagsStrings Utils::SpecicalMapUtils::getTerrainFlagsStrings(const std::string & terrainFlags)
{
	return chunkTerrainFlagsStrings();
}

Utils::terrainGameTileFlags Utils::SpecicalMapUtils::getTerrainFlags(const chunkTerrainFlagsStrings & chuTerFlgsStrs)
{
	terrainGameTileFlags ret;
	for (auto& chunk : ret)
	{
		for (auto& til : chunk)
		{
			til = std::bitset<TERRAIN_FLAGS_SIZE>();
		}
	}
	return ret;
}
