Debug:
	g++-5 -Wall -Wextra -ggdb -mmmx -msse -msse2 -msse3 -mfpmath=sse -std=c++14 -o SpaceColonizerGame *.cpp ./Utils/*.cpp -lallegro -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf -pthread
PerfTest:
	perf stat ./SpaceColonizerGame
Release:
	g++-5 -Wall -Wextra -O2 -mmmx -msse -msse2 -msse3 -mfpmath=sse -std=c++14 -o SpaceColonizerGame *.cpp ./Utils/*.cpp -lallegro -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf -pthread 

