#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\лаби\9тема\9.2\9.2\9.2B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92B
{
	TEST_CLASS(UnitTest92B)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int* c;
			int const i = 1;
			Students* S = new Students[1];
			c = Index_sort(S, 1);
			Assert::AreEqual(*c, 0);
		}
	};
}