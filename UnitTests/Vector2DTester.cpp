#include "stdafx.h"
#include "CppUnitTest.h"
#include <Vector.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Vector2DTests)
	{
	public:
		TEST_METHOD(MagitudeTests)
		{
			float expected = sqrtf(8.0f);
			Utils::Vector2D testVec1;
			testVec1.setX(2.0f);
			testVec1.setY(2.0f);

			Assert::AreEqual(expected, testVec1.getMagnitude());

			testVec1.setX(-2.0f);
			Assert::AreEqual(expected, testVec1.getMagnitude());
			testVec1.setY(-2.0f);
			Assert::AreEqual(expected, testVec1.getMagnitude());

			expected = sqrtf(229.0f);
			testVec1.setX(15.0f);
			Assert::AreEqual(expected, testVec1.getMagnitude());
		}

	};
}