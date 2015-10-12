#include "stdafx.h"
#include "CppUnitTest.h"
#include <Utils/StringUtils.h>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;
using std::vector;

namespace UnitTests
{		
	TEST_CLASS(StringUtilsTests)
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

			bool except = false;
			try
			{
				Utils::subString(testData, -1, 0);
			}
			catch (Exceptions::game_range_error&)
			{
				except = true;
			}
			Assert::IsTrue(except);

			except = false;
			try
			{
				Utils::subString(testData, 1, 0);
			}
			catch (Exceptions::game_range_error&)
			{
				except = true;
			}
			Assert::IsTrue(except);

			except = false;
			try
			{
				Utils::subString(testData, 1, 1);
			}
			catch (Exceptions::game_range_error&)
			{
				except = true;
			}
			Assert::IsTrue(except);

			except = false;
			try
			{
				Utils::subString(testData, 10000, 100000);
			}
			catch (Exceptions::game_range_error&)
			{
				except = true;
			}
			Assert::IsTrue(except);
		}

		TEST_METHOD(getStringBetweenTwoStringsTests)
		{
			string expected = R"(0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;)";
			string testData = R"(BEGINTEXTUREDEFS
0=Data/Images/Tiles/BlueTile.png;
1=Data/Images/Tiles/RedTile.png;
ENDTEXTUREDEFS
BEGINCHUNKTEXDATA)";
			Assert::AreEqual(expected, Utils::getStringBetweenTwoStrings(testData, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS"));
			//no new lines
			expected = R"(0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;)";
			testData = R"(BEGINTEXTUREDEFS0=Data/Images/Tiles/BlueTile.png;1=Data/Images/Tiles/RedTile.png;ENDTEXTUREDEFSBEGINCHUNKTEXDATA)";
			Assert::AreEqual(expected, Utils::getStringBetweenTwoStrings(testData, "BEGINTEXTUREDEFS", "ENDTEXTUREDEFS"));

			bool except = false;
			try
			{
				Utils::getStringBetweenTwoStrings(testData, "", "346534634tsdgs");
			}
			catch(Exceptions::game_invalid_argument&)
			{
				except = true;
			}
			Assert::IsTrue(except);
		}

		TEST_METHOD(splitStringTests)
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

			testData = R"(12345:
67890)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			testData = R"(12345
:67890)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			testData = R"(12345
:
67890)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}


			expected = {
				string("12345"),
				string("67890"),
				string("abcde")
			};

			testData = R"(12345:67890:abcde)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			testData = R"(12345
:67890:abcde)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			testData = R"(12345:
67890
:abcde)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			testData = R"(12345
:67890:
abcde)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			testData = R"(:12345:67890:abcde)";
			expectedLen = expected.size();
			Assert::AreEqual(expectedLen, Utils::splitString(testData, ':').size());
			for (size_t i = 0;i < expectedLen;i++)
			{
				Assert::AreEqual(expected.at(i), Utils::splitString(testData, ':').at(i));
			}

			bool except = false;
			try
			{
				Utils::splitString(testData, 'p');
			}
			catch (Exceptions::game_invalid_argument&)
			{
				except = true;
			}
			Assert::IsTrue(except);
		}

		TEST_METHOD(removeUpToCharTests)
		{
			string expected = R"(Data/Images/Tiles/BlueTile.png;)";
			string testData = R"(0=Data/Images/Tiles/BlueTile.png;)";

			Utils::removeUpToChar(testData, '=');
			Assert::AreEqual(expected, testData);

			bool except = false;
			try
			{
				Utils::removeUpToChar(testData, '[');
			}
			catch (Exceptions::game_invalid_argument&)
			{
				except = true;
			}
			Assert::IsTrue(except);
		}

		TEST_METHOD(removeAllWhiteSpaceTests)
		{
			string expected = R"(1234567890)";
			string testData = R"(1 2
3 4   5		6  78 
90)";
			Assert::AreEqual(expected, Utils::removeAllWhiteSpace(testData));
		}

		TEST_METHOD(ltrimTests)
		{
			string expected = R"(test)";
			string testData = R"(   test)";

			Utils::ltrim(testData);
			Assert::AreEqual(expected, testData);

			testData = R"(
test)";
			Utils::ltrim(testData);
			Assert::AreEqual(expected, testData);
		}

		TEST_METHOD(rtrimTests)
		{
			string expected = R"(test)";
			string testData = R"(test   )";

			Utils::rtrim(testData);
			Assert::AreEqual(expected, testData);

			testData = R"(test
)";
			Utils::rtrim(testData);
			Assert::AreEqual(expected, testData);
		}

		TEST_METHOD(trimTests)
		{
			string expected = R"(test)";
			string testData = R"(   test   )";

			Utils::trim(testData);
			Assert::AreEqual(expected, testData);

			testData = R"(
test
)";
			Utils::trim(testData);
			Assert::AreEqual(expected, testData);
		}
	};
}