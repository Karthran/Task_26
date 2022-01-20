#include <iostream>
#include <chrono>
#include "ArrSum.h"

auto genArray(std::vector<int>& vec, size_t elem_num)
{
	vec.clear();
	vec.reserve(elem_num);
	for (auto i{ 0 }; i < elem_num; ++i)
	{
		vec.push_back(rand() % 256);
	}
}

int main()
{
	ArrSum as;
	std::vector<int> vec{};
	std::vector<int> arr_sizes{ 100000,1000000,10000000 };
	std::vector<int> threads_num{ 1,2,4,8,16,32 };
	std::vector<std::vector<int>> result{};
	for (auto s{ 0 }; s < arr_sizes.size(); ++s)
	{
		auto current_array_size = arr_sizes[s];
		genArray(vec, current_array_size);
		std::vector<int> cur_res{};
		for (auto t{ 0 }; t < threads_num.size(); ++t)
		{
			auto ms_start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
			as.calcSum(vec, threads_num[t]);
			auto ms_stop = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
			std::chrono::milliseconds dif = ms_stop - ms_start;
			cur_res.push_back(dif.count());
			std::cout << as.getSum() << std::endl;
		}
		result.push_back(cur_res);
	}
	for (auto i{ 0 }; i < result.size(); ++i)
	{
		for (auto j{ 0 }; j < result[i].size(); ++j)
		{
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::getchar();
}

