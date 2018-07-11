#pragma once
#include "less_decorator.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

static bool isEvenCheck(int n)
{
	return n % 2 == 0;
}

class test_min_even_element
{
public:
	test_min_even_element()
	{
		std::vector<int> data_vector;

		int n = 25;
		std::generate_n(std::back_inserter(data_vector), 10, [&n]() { return n++; });
		auto t = minimal_element(data_vector.begin(), data_vector.end(), isEvenCheck);

		assert(*t == 26);
	}
};

static test_min_even_element the_test;