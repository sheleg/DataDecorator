#pragma once
#include <algorithm>
#include <ostream>

template<typename Data, typename Function>
class data_decorator
{
public:
	Data data_;
	Function filter_function_;
	data_decorator(Data data, Function function)
	:data_(data)
	, filter_function_(function) {}

	friend bool operator < (const data_decorator& data1, const data_decorator& data2)
	{
		auto b1 = data1.filter_function_(data1.data_);
		auto b2 = data2.filter_function_(data2.data_);

		if (b1 && b2)
		{
			return data1.data_ < data2.data_;
		}

		if (!b1 && !b2)
		{
			return true;
		}

		return b1;
	}
	friend std::ostream& operator << (std::ostream& os, const data_decorator& data)
	{
		os << "Data_dacorator is " << data.data_ << std::endl;
		return os;
	}
};