#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(TriangleTest)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double a = 6.7;
			double b = 4.5;
			double c = 8.0;
			double p = a + b + c;
			Triangle t = Triangle(a, b, c);
			Assert::AreEqual(p, t.perimeter());
		}

		TEST_METHOD(TestMethod2)
		{
			double a = 6.7;
			double b = 4.5;
			double c = 8.0; 
			double p = (a + b + c) / 2.0;
			double s = sqrt(p * (p - a) * (p - b) * (p - c));
			Triangle t = Triangle(a, b, c);
			Assert::AreEqual(s, t.area());
		}
		TEST_METHOD(TestMethod3)
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
		TEST_METHOD(TestMethod4)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(TestMethod5)
		{
			string data = "a = 6.7a, b = 4.5, c = 8.0";
			shared_ptr<IParser> parser = TriangleParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
