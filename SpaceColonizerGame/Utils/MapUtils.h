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
//#include "../GameTile.h"
#include "SpriteUtils.h"
#include "FileUtils.h"
#include "StringUtils.h"
#include "../Map.h"
#include "../Chunk.h"

/*
Map format is as follows

List of textures that are going to be used in the map, starting with BEGINTEXTUREDEFS, followed by the data, with ; seperating each row, followed by ENDTEXTUREDEFS at the end of the section

data format
number=Path to texture;
with no spaces and the numbers are in sequence (0,1,2,3,4,etc) up to a maximum of 1024

ex
BEGINTEXTUREDEFS
0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;
ENDTEXTUREDEFS

Placement of the various tiles on the map, starting with BEGINTEXTUREMAP, followed by the data, with ; seperating each row, followed by ENDTEXTUREMAP at the end of the section

data format
number space number space number;
number space number space number;

where the number corrisponds to one of the texture defs in the previous section

ex
BEGINTEXTUREMAP
0 1 1 0 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1 1 0;
0 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1;
1 0 1 0 1 1 1 0 1 1 0 1 0 1 0 1 0 1 0 1 0;
1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1;
ENDTEXTUREMAP


the file ends with an empty line

*/

namespace Utils
{
	std::shared_ptr<Map> loadMap(const std::string filepath);
	namespace SpecicalMapUtils
	{
		//breaks the gametile info into GAMETILES_PER_COL sized chunks
		std::array<std::vector<GameTile>, GAMETILES_PER_COL> getRowDataPerChunk(const std::vector<std::vector<GameTile>> tiles);
		//returns a vector containing the raw chunk data for all the chunks in the game
		std::vector<std::array<std::array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW>> getChunkData(const std::array<std::vector<GameTile>, GAMETILES_PER_COL> rowDataPerChunk);
		//grabs the first GAMETILES_PER_ROW or the remaining data from that row is contains less than GAMETILES_PER_ROW from the given data for each row of rowDataPerChunk and returns it
		std::array<std::array<GameTile, GAMETILES_PER_COL>, GAMETILES_PER_ROW> getChunk(const std::array<std::vector<GameTile>, GAMETILES_PER_COL> rowDataPerChunk);
	}
}


#endif
