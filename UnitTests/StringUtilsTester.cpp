#include "stdafx.h"
#include "CppUnitTest.h"
#include <Utils/StringUtils.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;
using std::vector;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(findFirstStringInStringTests)
		{
			int expected = 0;
			string testData = R"(BEGINTEXTUREDEFS
0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;
ENDTEXTUREDEFS
BEGINCHUNKTEXDATA)";

			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "BEGINTEXTUREDEFS", 0));
			//81 characters and 3 newlines = 84
			expected = 84;
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "ENDTEXTUREDEFS", 0));
			expected = -1;
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "asdf", 0));
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "", 0));


			testData = R"(BEGINTEXTUREDEFS0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;ENDTEXTUREDEFSBEGINCHUNKTEXDATA)";
			expected = 0;
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "BEGINTEXTUREDEFS", 0));
			expected = 81;
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "ENDTEXTUREDEFS", 0));
			expected = -1;
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "asdf", 0));
			Assert::AreEqual(expected, Utils::findFirstStringInString(testData, "", 0));
		}

		TEST_METHOD(subStringTests)
		{
			string expected = R"(0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;)";
			string testData = R"(BEGINTEXTUREDEFS
0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;
ENDTEXTUREDEFS
BEGINCHUNKTEXDATA)";

			Assert::AreEqual(expected, Utils::subString(testData, 17, 83));
			testData = R"(BEGINTEXTUREDEFS0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;ENDTEXTUREDEFSBEGINCHUNKTEXDATA)";
			expected = R"(0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;)";
			Assert::AreEqual(expected, Utils::subString(testData, 16, 81));
		}

		TEST_METHOD(getStringBetweenTwoStringsTests)
		{
			string expected = R"(0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;)";
			string testData = R"(BEGINTEXTUREDEFS
0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;
ENDTEXTUREDEFS
BEGINCHUNKTEXDATA)";
			Assert::AreEqual(expected, Utils::getStringBetweenTwoStrings(testData, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS"));
			//no new lines
			testData = R"(BEGINTEXTUREDEFS0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;ENDTEXTUREDEFSBEGINCHUNKTEXDATA)";
			Assert::AreEqual(expected, Utils::getStringBetweenTwoStrings(testData, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS"));

			//Assert::ExpectException<Exceptions::game_invalid_argument>(Utils::getStringBetweenTwoStrings(testData, "", "346534634tsdgs"));
		}


		TEST_METHOD(splitStringTest)
		{
			vector<string> expected = {
				string("12345"),
				string("67890")
			};
			string testData = R"(12345:67890)";
			size_t expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

		}
	};
}