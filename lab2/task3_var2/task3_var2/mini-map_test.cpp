#include "stdafx.h"
#include "../dictionary/mini-map.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(read_dictionary_from_file_function)

BOOST_AUTO_TEST_CASE()
{
	map <string, string> expextedDictionary = {{"cat", "кошка"}, {"dog", "собака"}};
	map <string, string> dictionary;
	stringStream input = "cat кошка dog собака";
	ReadDictionaryFromFile(input, dictionary);
	BOOST_CHECK(dictionary == expextedDictionary);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(read_dictionary_from_file_function)

BOOST_AUTO_TEST_CASE()
{
	map <string, string> expextedDictionary = { { "cat", "кошка" },{ "dog", "собака" } };
	map <string, string> dictionary;
	stringStream input = "cat кошка dog собака";
	ReadDictionaryFromFile(input, dictionary);
	BOOST_CHECK(dictionary == expextedDictionary);
}

BOOST_AUTO_TEST_SUITE_END()
