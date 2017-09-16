#include "stdafx.h"
#include "../dictionary/mini-map.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(read_dictionary_from_file_function)

BOOST_AUTO_TEST_CASE()
{
	map <string, string> expextedDictionary = {{"cat", "�����"}, {"dog", "������"}};
	map <string, string> dictionary;
	string input ("cat:����� dog:������");
	ReadDictionary(input, dictionary);
	BOOST_CHECK(dictionary == expextedDictionary);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(read_dictionary_from_file_function)

BOOST_AUTO_TEST_CASE()
{
	string expectedDictionary = "cat:�����";
	map <string, string> dictionary = {{"cat", "�����"}};
	stringstream output("");
	BOOST_CHECK(output.str() == expectedDictionary);
}

BOOST_AUTO_TEST_SUITE_END()
