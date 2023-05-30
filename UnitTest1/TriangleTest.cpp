#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(TriangleTest)
	{
	public:
		TEST_METHOD(test_Perimeter)
		{
			double a = 6.7;
			double b = 4.5;
			double c = 8.0;
			double p = a + b + c;
			Triangle t = Triangle(a, b, c);
			Assert::AreEqual(p, t.perimeter());
		}

		TEST_METHOD(test_Area)
		{
			double a = 6.7;
			double b = 4.5;
			double c = 8.0; 
			double p = (a + b + c) / 2.0;
			double s = sqrt(p * (p - a) * (p - b) * (p - c));
			Triangle t = Triangle(a, b, c);
			Assert::AreEqual(s, t.area());
		}
		TEST_METHOD(test_Parser_Success)
		{
			string data = "a = 6.7, b = 4.5, c = 8.0";
			double a = 6.7;
			double b = 4.5;
			double c = 8.0;
			Triangle t = Triangle(a, b, c);
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNotNull(result.get(), L"Should not return null", LINE_INFO());
			Assert::AreEqual(t.area(), result->area());
			Assert::AreEqual(t.perimeter(), result->perimeter());
		}
		TEST_METHOD(test_Parser_InvalidStringFormat)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidValue)
		{
			string data = "a = 6.7a, b = 4.5, c = 8.0";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidTriangle)
		{
			string data = "a = 1.0, b = 2.0, c = 3.0";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(Triangle_Parser_Missing_Value_Test)
		{
			string data = "a = , b = 4.0, c = 5.0";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(Triangle_Parser_Missing_Variable_Test)
		{
			string data = "= 3.0, b = 4.0, c = 5.0";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
