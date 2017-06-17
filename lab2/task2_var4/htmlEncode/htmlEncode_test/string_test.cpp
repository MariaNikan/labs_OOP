#include "stdafx.h"
#include "../task2_var4/string.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(replace_substring_function)

	BOOST_AUTO_TEST_CASE(returns_replaced_substring)
	{
		string expectedString = "is not red empty string!";
		string line = "is not &empty string!";
		char symbol = '&';
		string text = "red ";
		ReplaceSubstring(line, symbol, text);
		BOOST_CHECK(line == expectedString);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(html_encode_function)

BOOST_AUTO_TEST_CASE(returns_replaced_string)
{
	string expectedString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	string line = "Cat <says> ""Meow"". M&M’s ";
	string text = HtmlEncode(line);
	BOOST_CHECK(text == expectedString);
}

BOOST_AUTO_TEST_SUITE_END()