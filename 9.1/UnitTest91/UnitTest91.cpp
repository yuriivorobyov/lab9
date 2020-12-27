#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\лаби\9тема\9.1\9.1\9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91A
{
	TEST_CLASS(UnitTest91)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int c;
			int const i = 1;
			Students* S = new Students[1];
			c = Find_Students(S, 1);
			Assert::AreEqual(c, 1);
		}
	};
}