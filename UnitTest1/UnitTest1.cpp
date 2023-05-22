#include "pch.h"
#include "CppUnitTest.h"
#include "../ShapesParser/IShape.h"
#include "../ShapesParser/IShape.cpp"
#include "../ShapesParser/Circle.h"
#include "../ShapesParser/Circle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double r = 6.7;
			double p = 2 * 3.14 * r;
			Circle c(r);
			Assert::AreEqual(p, c.perimeter());
		}

		TEST_METHOD(TestMethod2)
		{
			double r = 4.7;
			double s = r * r * 3.14;
			Circle c(r);
			Assert::AreEqual(s, c.area());
		}
	};
}
