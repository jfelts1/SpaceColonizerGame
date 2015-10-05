/*
James Felts 2015
*/
#ifndef MAPUTILS_H
#define MAPUTILS_H
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
#include "../Map.h"
#include "../Chunk.h"

namespace Utils
{
	typedef std::array<std::string, MAX_NUMBER_TILE_TEXTURES> texturePathsDefs;
	typedef std::vector<std::string> textureDefsStrings;

	typedef std::vector<std::string> chunkDataStrings;

	typedef std::vector<std::string> chunkTerrainFlagsStrings;
	typedef std::vector<std::array<std::bitset<TERRAIN_FLAGS_SIZE>, GAMETILES_PER_ROW*GAMETILES_PER_COL>> terrainGameTileFlags;

	static_assert(MAX_NUMBER_TILE_TEXTURES == GAMETILES_PER_COL*GAMETILES_PER_ROW, "MAX_NUMBER_TILE_TEXTURES must equal GAMETILES_PER_COL*GAMETILES_PER_ROW");

	std::unique_ptr<Map> loadMap(const std::string filepath);
	namespace SpecicalMapUtils
	{
		texturePathsDefs getTexturePathArray(const textureDefsStrings& texDefsStrs);
		//constructs the chunks from the given data
		std::vector<Chunk> getChunks(const chunkDataStrings& chuDatStr,const texturePathsDefs& texPathDefs, const terrainGameTileFlags& chuTerFlgs);
		chunkTerrainFlagsStrings getTerrainFlagsStrings(const std::string& terrainFlags);
		terrainGameTileFlags getTerrainFlags(const chunkTerrainFlagsStrings& chuTerFlgsStrs);
	}
}


#endif
