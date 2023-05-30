#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(CircleTest)
	{
	public:
		TEST_METHOD(test_Perimeter)
		{
			double r = 6.7;
			double p = 2 * 3.14 * r;
			Circle c = Circle(r);
			Assert::AreEqual(p, c.perimeter());
		}

		TEST_METHOD(test_Area)
		{
			double r = 4.7;
			double s = r * r * 3.14;
			Circle c = Circle(r);
			Assert::AreEqual(s, c.area());
		}
		TEST_METHOD(test_Parser_Success)
		{
			string data = "r = 4.7";
			double r = 4.7;
			Circle c = Circle(r);
			shared_ptr<IParser> parser = CircleParser::getInstance();
			auto result = parser->parse((stringstream)data);
			
			Assert::IsNotNull(result.get(), L"Should not return null", LINE_INFO());
			Assert::AreEqual(c.area(), result->area());
			Assert::AreEqual(c.perimeter(), result->perimeter());
		}
		TEST_METHOD(test_Parser_InvalidStringFormat)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = CircleParser::getInstance();
			auto result = parser->parse((stringstream)data); 

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidValue)
		{
			string data = "r = 3.5a";
			shared_ptr<IParser> parser = CircleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidCircle)
		{
			string data = "r = 0.0";
			shared_ptr<IParser> parser = CircleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(Parser_Missing_Value_Test)
		{
			string data = "r = ";
			shared_ptr<IParser> parser = CircleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(Parser_Missing_Variable_Test)
		{
			string data = "= 4.7";
			shared_ptr<IParser> parser = CircleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
