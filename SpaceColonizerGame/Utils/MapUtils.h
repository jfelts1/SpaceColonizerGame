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
#include "../GameTile.h"
#include "SpriteUtils.h"
#include "FileUtils.h"
#include "StringUtils.h"

/*
Map format is as follows

List of textures that are going to be used in the map, starting with BEGINTEXTUREDEFS, followed by the data, with ; seperating each row, followed by ENDTEXTUREDEFS at the end of the section

data format
number=Path to texture;
with no spaces

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
	std::vector<std::vector<GameTile>> loadMap(const std::string filepath);
}


#endif
