#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(DiamondTest)
	{
	public:
		TEST_METHOD(test_Perimeter)
		{
			double diag_p = 6.7;
			double diag_q = 5.4;
			double p = 2 * sqrt(diag_p * diag_p + diag_q * diag_q);
			Diamond d = Diamond(diag_p, diag_q);
			Assert::AreEqual(p, d.perimeter());
		}

		TEST_METHOD(test_Area)
		{
			double diag_p = 6.7;
			double diag_q = 5.4;
			double s = diag_p * diag_q / 2.0;
			Diamond d = Diamond(diag_p, diag_q);
			Assert::AreEqual(s, d.area());
		}
		TEST_METHOD(TestMettest_Parser_Success)
		{
			string data = "p = 6.7, q = 5.4";
			double diag_p = 6.7;
			double diag_q = 5.4;
			Diamond d = Diamond(diag_p, diag_q);
			shared_ptr<IParser> parser = DiamondParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNotNull(result.get(), L"Should not return null", LINE_INFO());
			Assert::AreEqual(d.area(), result->area());
			Assert::AreEqual(d.perimeter(), result->perimeter());
		}
		TEST_METHOD(test_Parser_InvalidStringFormat)
		{
			string data = "Undefined";
			shared_ptr<IParser> parser = DiamondParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidValue)
		{
			string data = "p = 3.5a, q = 6.7";
			shared_ptr<IParser> parser = DiamondParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
		TEST_METHOD(test_Parser_InvalidDiamond)
		{
			string data = "p = 0.0, q = 6.7";
			shared_ptr<IParser> parser = DiamondParser::getInstance();
			auto result = parser->parse((stringstream)data);

			Assert::IsNull(result.get(), L"Should return null", LINE_INFO());
		}
	};
}
