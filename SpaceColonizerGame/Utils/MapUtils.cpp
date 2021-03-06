/*
James Felts 2015
*/
#include "MapUtils.h"

using std::string;
using std::vector;
using std::array;
using std::istringstream;

std::unique_ptr<Map> Utils::loadMap(const string& rawString)
{
	vector<Chunk> chunks;
	texturePathsDefs texturePaths;
	chunkDataStrings mapData;
	terrainGameTileFlags terrainFlags;

	string texureDefs;
	string mapDataStr;
	string terrainFlagsStr;

	texureDefs = getStringBetweenTwoStrings(rawString, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS");
	mapDataStr = getStringBetweenTwoStrings(rawString, "BEGINCHUNKTEXDATA", "ENDCHUNKTEXDATA");

	MapUtilHelperFuncs::getTexturePaths(texturePaths, texureDefs);

	MapUtilHelperFuncs::getTerrainFlags(terrainFlags, terrainFlagsStr);

	mapData = splitString(mapDataStr, 'P');
	chunks = MapUtilHelperFuncs::getChunks(mapData,texturePaths,terrainFlags);
	chunks.shrink_to_fit();

	return std::make_unique<Map>(chunks);
}

//returns an array containing the file paths to every game tile texture
//throws game_out_of_range
Utils::texturePathsDefs Utils::MapUtilHelperFuncs::getTexturePathArray(const textureDefsStrings& texDefsStrs)
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
				throw Exceptions::game_out_of_range("the number attached to the texure is out of range.","MapUtils.cpp","getTexturePathArray");
			}
			removeUpToChar(texPath, '=');
			ret[static_cast<size_t>(textureIndex)] = move(texPath);
		}
	}
	catch (Exceptions::game_invalid_argument& e)
	{
		GET_LOG.writeToLog(e.what(),"MapUtils.cpp","getTexturePathArray",Error,e.getThrowingFile(),e.getThrowingFunction());
	}
	return ret;
}

vector<Chunk> Utils::MapUtilHelperFuncs::getChunks(const chunkDataStrings& chuDatStr, const texturePathsDefs& texPathDefs, const terrainGameTileFlags& chuTerFlgs)
{
	vector<Chunk> ret;
	istringstream chunkStrStream;
	vector<string> tmp;
	chunkData chuDat;
	GameTile temp;
	float x, y;
	short val;
	size_t chunkIndex;
	for (size_t j = 0;j < chuDatStr.size();j++)
	{
		chunkIndex = 0;
		tmp = splitString(chuDatStr[j], ';');
		//get the position data
		chunkStrStream = istringstream(tmp[0]);
		chunkStrStream >> x;
		chunkStrStream >> y;
		//read the chunk data
		for (size_t i = 1;i < tmp.size()-1;i++)
		{
			val = 0;
			chunkStrStream = istringstream(tmp[i]);
			//read each chunk row one tile at a time
			while (!chunkStrStream.eof())
			{
				chunkStrStream >> val;
				if (val <0 || val > MAX_NUMBER_TILE_TEXTURES - 1)
				{
					throw Exceptions::game_out_of_range("The number to look up the texture is out of range.","MapUtils.cpp","getChunks");
				}
				//load the texture into the tileHelper array
				GameTile::loadTileHelper(texPathDefs[static_cast<size_t>(val)], val);
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

	return ret;
}

//placeholder stubs since the actual flags aren't part of the map format yet
Utils::chunkTerrainFlagsStrings Utils::MapUtilHelperFuncs::getTerrainFlagsStrings(const string & terrainFlags)
{
	return chunkTerrainFlagsStrings();
}

Utils::terrainGameTileFlags Utils::MapUtilHelperFuncs::getTerrainFlagsHelper(const chunkTerrainFlagsStrings & chuTerFlgsStrs)
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
