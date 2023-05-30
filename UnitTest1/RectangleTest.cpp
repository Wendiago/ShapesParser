#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(RectangleTest)
	{
	public:
		TEST_METHOD(test_Perimeter)
		{
			double w = 6.7;
			double h = 5.4;
			double p = (w + h) * 2;
			Rectangle r = Rectangle(w, h);
			Assert::AreEqual(p, r.perimeter());
		}

		TEST_METHOD(test_Area)
		{
			double w = 6.7;
			double h = 5.4;
			double s = w * h;			
			Rectangle r = Rectangle(w, h);
			Assert::AreEqual(s, r.area());
		}
		TEST_METHOD(test_Parser_Success)
		{
			string data = "w = 6.7, h = 5.4";
			double w = 6.7;
			double h = 5.4;
			Rectangle r = Rectangle(w, h);
			shared_ptr<IParser> parser = RectangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNotNull(result.get(), L"Should not return null", LINE_INFO());
			Assert::AreEqual(r.area(), result->area());
			Assert::AreEqual(r.perimeter(), result->perimeter());
		}
		TEST_METHOD(test_Parser_InvalidStringFormat)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = RectangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidValue)
		{
			string data = "w = 6.7a, h = 5.4";
			shared_ptr<IParser> parser = RectangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidRectangle)
		{
			string data = "w = 6.7, h = 0.0";
			shared_ptr<IParser> parser = RectangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}

		TEST_METHOD(Rectangle_Parser_Missing_Value_Test)
		{
			string data = "w = , h = 8.0";
			shared_ptr<IParser> parser = RectangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}

		TEST_METHOD(Rectangle_Parser_Missing_Variable_Test)
		{
			string data = "= 5.0, h = 8.0";
			shared_ptr<IParser> parser = RectangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
