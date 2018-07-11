#pragma once
#include <iostream>

template<typename Data, typename Filter, typename LessRelation = std::less<Data>>
class minmax_decorator
{
	LessRelation less_;
	Filter filter_;
	bool is_max_rel_;
public:
	minmax_decorator(Filter filter, bool is_max_rel = false, LessRelation less_rel = LessRelation())
		: less_(less_rel)
		, filter_(filter)
		, is_max_rel_(is_max_rel){}

	bool operator () (const Data& data1, const Data& data2)
	{
		auto b1 = filter_(data1);
		auto b2 = filter_(data2);

		if (is_max_rel_)
			return b1 && ((b1 == b2)
				? !less_(data1, data2)
				: true);

		return b1 && ((b1 == b2)
			? less_(data1, data2)
			: true);
	}
};

template<class InputIterator, typename Filter, typename LessRelation = std::less<decltype(*(std::declval<InputIterator>()))>>
InputIterator get_element(InputIterator first, InputIterator last, Filter filter, bool is_max_rel = false, LessRelation less_rel = LessRelation())
{
	minmax_decorator<decltype(*first), Filter, LessRelation> less_of_even(filter, is_max_rel, less_rel);
	auto b = std::min_element(first, last, less_of_even);

	return isEvenCheck(*b) ? b : last;
}

template<class InputIterator, typename Filter, typename LessRelation = std::less<decltype(*(std::declval<InputIterator>()))>>
InputIterator minimal_element(InputIterator first, InputIterator last, Filter filter, LessRelation less_rel = LessRelation())
{
	return get_element(first, last, filter, false, less_rel);
}

template<class InputIterator, typename Filter, typename LessRelation = std::less<decltype(*(std::declval<InputIterator>()))>>
InputIterator maximal_element(InputIterator first, InputIterator last, Filter filter, LessRelation less_rel = LessRelation())
{
	return get_element(first, last, filter, true, less_rel);
}

