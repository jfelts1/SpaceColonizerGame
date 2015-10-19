#include "stdafx.h"
#include "CppUnitTest.h"
#include <Vector.h>
#define TOLERANCE 0.0001f

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Utils::Vector2D;

namespace UnitTests
{		
	TEST_CLASS(Vector2DTests)
	{
	public:
		TEST_METHOD(MagitudeTests)
		{
			auto expected = sqrtf(8.0f);
			Vector2D testVec1;
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

		TEST_METHOD(TruncateTests)
		{
			auto expected = 10.0f;
			Vector2D testData(10.0f,10.0f);
			testData.truncate(10.0f);

			Assert::AreEqual(expected,testData.getMagnitude(),0.0001f);

			//test truncate negative values
			testData.setX(-10.0f);
			testData.setY(10.0f);
			testData.truncate(10.0f);

			Assert::AreEqual(expected, testData.getMagnitude(), 0.0001f);

			//test truncating to 0
			expected = 0.0f;
			testData.truncate(0.0f);
			Assert::AreEqual(expected, testData.getMagnitude());

			//test truncating to larger than the magitude (should do nothing)
			expected = sqrtf(50.0f);
			testData.setX(5.0f);
			testData.setY(5.0f);
			testData.truncate(20.0f);
			Assert::AreEqual(expected, testData.getMagnitude());
		}

		TEST_METHOD(EqualityTests)
		{
			Vector2D expected(100.0f, 100.0f);
			Vector2D testData(100.0f, 100.f);
			
			Assert::IsTrue(expected == testData);
			Assert::IsTrue(expected.equals(testData));

			testData = Vector2D(-100.0f, -100.0f);

			Assert::IsTrue(expected != testData);
			Assert::IsFalse(expected == testData);
			Assert::IsFalse(expected.equals(testData));

		}

		TEST_METHOD(AddTests)
		{
			Vector2D expected(10.0f,10.0f);
			Vector2D testData(5.0f, -5.0f);
			Vector2D testData2(5.0f, 15.0f);
			auto testDataRes = testData + testData2;

			Assert::AreEqual(expected.getX(), testDataRes.getX(), TOLERANCE);
			Assert::AreEqual(expected.getY(), testDataRes.getY(), TOLERANCE);

			//add to zero
			expected = Vector2D(0.0f, 0.0f);
			testData = Vector2D(100.0f, 50.0f);
			testData2 = Vector2D(-100.0f, -50.0f);
			testDataRes = testData + testData2;

			Assert::AreEqual(expected.getX(), testDataRes.getX(), TOLERANCE);
			Assert::AreEqual(expected.getY(), testDataRes.getY(), TOLERANCE);

			//large numbers
			expected = Vector2D(1'000'000.0f, 5'000'000.0f);
			testData = Vector2D(500'000.0f, 2'500'000.0f);
			testData2 = Vector2D(500'000.0f, 2'500'000.0f);
			testDataRes = testData + testData2;

			Assert::AreEqual(expected.getX(), testDataRes.getX(), TOLERANCE);
			Assert::AreEqual(expected.getY(), testDataRes.getY(), TOLERANCE);
		}

		TEST_METHOD(SubtractionTests)
		{
			Vector2D expected(100.0f, 25.0f);
			Vector2D testData(150.0f, 60.0f);
			Vector2D testData2(50.0f, 35.0f);
			auto testDataRes = testData - testData2;

			Assert::AreEqual(expected.getX(), testDataRes.getX(),TOLERANCE);
			Assert::AreEqual(expected.getY(), testDataRes.getY(), TOLERANCE);

			//subtract to 0
			expected = Vector2D();
			testData = Vector2D(100.0f, 100.0f);
			testDataRes = testData - testData;

			Assert::AreEqual(expected.getX(), testDataRes.getX(), TOLERANCE);
			Assert::AreEqual(expected.getY(), testDataRes.getY(), TOLERANCE);

			//large value test
			expected = Vector2D(100.0f, 100.0f);
			testData = Vector2D(5'000'000.0f, 1'000'000.0f);
			testData2 = Vector2D(4'999'900.0f, 999'900.0f);
			testDataRes = testData - testData2;

			Assert::AreEqual(expected.getX(), testDataRes.getX(), TOLERANCE);
			Assert::AreEqual(expected.getY(), testDataRes.getY(), TOLERANCE);
		}

		TEST_METHOD(DotProductTests)
		{
			auto expected = 77.0f;
			Vector2D testData(10.0f, 9.0f);
			Vector2D testData2(5.0f, 3.0f);

			Assert::AreEqual(expected, testData.dotProduct(testData2), TOLERANCE);

			expected = -77.0f;
			testData = Vector2D(10.0f, 9.0f);
			testData2 = Vector2D(-5.0f, -3.0f);
			
			Assert::AreEqual(expected, testData.dotProduct(testData2), TOLERANCE);
		}
	};
}