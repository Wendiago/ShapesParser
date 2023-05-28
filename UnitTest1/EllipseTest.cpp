#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(EllipseTest)
	{
	public:
		TEST_METHOD(test_Perimeter)
		{
			double major = 6.7;
			double minor = 5.4;
			double a = major / 2.0;
			double b = minor / 2.0;
			double p = 3.14 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
			Ellipse e = Ellipse(major, minor);
			Assert::AreEqual(p, e.perimeter());
		}

		TEST_METHOD(test_Area)
		{
			double major = 6.7;
			double minor = 5.4;
			double a = major / 2.0;
			double b = minor / 2.0;
			double s = a * b * 3.14;
			Ellipse e = Ellipse(major, minor);
			Assert::AreEqual(s, e.area());
		}
		TEST_METHOD(test_Parser_Success)
		{
			string data = "A = 6.7, B = 5.4";
			double major = 6.7;
			double minor = 5.4;
			Ellipse e = Ellipse(major, minor);
			shared_ptr<IParser> parser = EllipseParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNotNull(result.get(), L"Should not return null", LINE_INFO());
			Assert::AreEqual(e.area(), result->area());
			Assert::AreEqual(e.perimeter(), result->perimeter());
		}
		TEST_METHOD(test_Parser_InvalidStringFormat)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = EllipseParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidValue)
		{
			string data = "A = 3.5a, B = 6.7";
			shared_ptr<IParser> parser = EllipseParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidEllipse)
		{
			string data = "A = 3.5, B = 0.0";
			shared_ptr<IParser> parser = EllipseParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
