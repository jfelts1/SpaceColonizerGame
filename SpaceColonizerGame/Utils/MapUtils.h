/*
James Felts 2015
*/
#ifndef MAPUTILS_H
#define MAPUTILS_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "SpriteUtils.h"
#include "FileUtils.h"
#include "StringUtils.h"
#include "LogUtils.h"
#include "../GameExceptions.h"
#include "../Map.h"
#include "../Chunk.h"

namespace Utils
{
	//typedefs that are useful when loading maps
	typedef std::array<std::string, MAX_NUMBER_TILE_TEXTURES> texturePathsDefs;
	typedef std::vector<std::string> textureDefsStrings;

	typedef std::vector<std::string> chunkDataStrings;

	typedef std::vector<std::string> chunkTerrainFlagsStrings;
	typedef std::vector<std::array<std::bitset<TERRAIN_FLAGS_SIZE>, GAMETILES_PER_ROW*GAMETILES_PER_COL>> terrainGameTileFlags;

	std::unique_ptr<Map> loadMap(const std::string& rawString);
	namespace SpecicalMapUtils
	{
		//returns an array containing the file paths to every game tile texture
		texturePathsDefs getTexturePathArray(const textureDefsStrings& texDefsStrs);
		//constructs the chunks from the given data
		//throws game_out_of_range
		std::vector<Chunk> getChunks(const chunkDataStrings& chuDatStr,const texturePathsDefs& texPathDefs, const terrainGameTileFlags& chuTerFlgs);
		chunkTerrainFlagsStrings getTerrainFlagsStrings(const std::string& terrainFlags);
		terrainGameTileFlags getTerrainFlags(const chunkTerrainFlagsStrings& chuTerFlgsStrs);
	}
}


#endif
