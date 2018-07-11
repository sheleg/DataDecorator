#pragma once
#include <iostream>

template<typename Data, typename Filter, typename LessRelation = std::less<Data>>
class less_decorator
{
	LessRelation less_;
	Filter filter_; 

public:
	less_decorator(Filter filter, LessRelation less_rel = LessRelation())
		: less_(less_rel)
		, filter_(filter) {}

	bool operator () (const Data& data1, const Data& data2)
	{
		auto b1 = filter_(data1);
		auto b2 = filter_(data2);

		return b1 && ((b1 == b2)
			? less_(data1, data2)
			: true);
	}
};

template<class InputIterator, typename Filter, typename LessRelation = std::less<decltype(*(std::declval<InputIterator>()))>>
InputIterator minimal_element(InputIterator first, InputIterator last, Filter filter, LessRelation less_rel = LessRelation())
{
	less_decorator<decltype(*first), Filter, LessRelation> less_of_even(filter, less_rel);
	auto b = std::min_element(first, last, less_of_even);

	return isEvenCheck(*b) ? b : last;
}

