#include "stdafx.h"
#include "../task1_var2/double_vector.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(read_numbers_function)

	BOOST_AUTO_TEST_CASE(returns_empty_vector_if_input_stream_is_empty)
	{
		stringstream inputStream("");
		vector<double> numbers;
		ReadNumbers(inputStream, numbers);
		BOOST_CHECK(numbers.empty());
	}

	BOOST_AUTO_TEST_CASE(returns_empty_vector_if_input_stream_is_invalid)
	{
		stringstream inputStream("2.1 0 ch 7");
		vector<double> numbers;
		ReadNumbers(inputStream, numbers);
		BOOST_CHECK(numbers.empty());
	}

	BOOST_AUTO_TEST_CASE(returns_expected_vector_if_input_stream_is_valid)
	{
		vector<double> expectedNumbers = {12.7, -12.7, 0, 1.1, -100.2};
		stringstream inputStream("12.7 -12.7 0 1.1 -100.2");
		vector<double> numbers;
		ReadNumbers(inputStream, numbers);
		BOOST_CHECK(numbers == expectedNumbers);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(sort_numbers_function)

	BOOST_AUTO_TEST_CASE(returns_sorted_vector)
	{
		vector<double> expectedNumbers = { -100.2, -12.7, 0, 1.1, 12.7 };
		vector<double> numbers = { 12.7, -12.7, 0, 1.1, -100.2 };
		SortNumbers(numbers);
		BOOST_CHECK(numbers == expectedNumbers);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(find_min_number_function)

	BOOST_AUTO_TEST_CASE(returns_min_number_from_vector)
	{
		double expectedMinNumber = -100.2;
		vector<double> numbers = { 12.7, -12.7, 0, 1.1, -100.2 };
		double minNumber = FindMinNumber(numbers);
		BOOST_CHECK_EQUAL(minNumber, expectedMinNumber);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(multiply_numbers_by_number_function)

	BOOST_AUTO_TEST_CASE(returns_expected_vector_if_vector_isnt_empty)
	{
		vector<double> expectedNumbers = { -12.7, 12.7, 0, -1.1, 100.2 };
		double number = -1;
		vector<double> numbers = { 12.7, -12.7, 0, 1.1, -100.2 };
		MultiplyNumbersByNumber(numbers, number);
		BOOST_CHECK(numbers == expectedNumbers);
	}

	BOOST_AUTO_TEST_CASE(returns_empty_vector_if_vector_is_empty)
	{
		vector<double> expectedNumbers;
		double number = -1;
		vector<double> numbers;
		MultiplyNumbersByNumber(numbers, number);
		BOOST_CHECK(numbers == expectedNumbers);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(print_out_result_function)
	
	BOOST_AUTO_TEST_CASE(prints_out_expexted_vector)
	{
		string expectedOutputStringStream = "12.710 -12.745 0.000 1.100 -100.230 ";
		stringstream outputStream("");
		vector<double> numbers = { 12.70975, -12.745, 0, 1.1, -100.23 };
		PrintOutResult(outputStream, numbers);
		BOOST_CHECK_EQUAL(outputStream.str(), expectedOutputStringStream);
	}

BOOST_AUTO_TEST_SUITE_END()