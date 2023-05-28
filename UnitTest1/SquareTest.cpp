#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(SquareTest)
	{
	public:
		TEST_METHOD(test_Perimeter)
		{
			double a = 6.7;
			double p = a * 4;
			Square sq = Square(a);
			Assert::AreEqual(p, sq.perimeter());
		}

		TEST_METHOD(test_Area)
		{
			double a = 6.7;
			double s = a * a;
			Square sq = Square(a);
			Assert::AreEqual(s, sq.area());
		}
		TEST_METHOD(test_Parser_Success)
		{
			string data = "a = 6.7";
			double a = 6.7;
			Square sq = Square(a);
			shared_ptr<IParser> parser = SquareParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNotNull(result.get(), L"Should not return null", LINE_INFO());
			Assert::AreEqual(sq.area(), result->area());
			Assert::AreEqual(sq.perimeter(), result->perimeter());
		}
		TEST_METHOD(test_Parser_InvalidStringFormat)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = SquareParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidValue)
		{
			string data = "a = 3.5a";
			shared_ptr<IParser> parser = SquareParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidSquare)
		{
			string data = "a = 0.0";
			shared_ptr<IParser> parser = SquareParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
