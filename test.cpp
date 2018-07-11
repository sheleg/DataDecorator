#include "data_decorator.h"
//#include "less_decorator.h"
#include "minmax_decorator.h"
#include <vector>
#include <string>
#include <iterator>

static bool isEvenCheck(int n)
{
	return n % 2 == 0;
}

int main()
{
	std::vector<int> data_vector;

	int n = 25;
	std::generate_n(std::back_inserter(data_vector), 10, [&n]() { return n++; });
	auto t = minimal_element(data_vector.begin(), data_vector.end(), isEvenCheck, std::less<int>());
	std::cout << *t;
	return 0;
}