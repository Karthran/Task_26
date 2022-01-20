#include <iostream>
#include "ArrSum.h"

auto ArrSum::calcSum(const std::vector<int>& array, size_t section_num) -> void
{
	auto arr_size{ array.size() };
	auto sec_size{ arr_size / section_num };
	_thread_sum.clear();
	threads.clear();
	for (auto i{ 0 }; i < section_num; ++i)
	{
		_thread_sum.push_back(0);
		threads.emplace_back(std::thread(&ArrSum::section_sum, this, array, i, sec_size));
	}

	_sum = 0;
	for (auto& thread : threads)
	{
		if(thread.joinable()) thread.join();
	}
//	std::cout << "Sum: " << sum << std::endl;
}

auto ArrSum::section_sum(const std::vector<int>& array, size_t section_num, size_t section_size) -> void
{
	_thread_sum[section_num] = 0;
	auto start_index{ section_num * section_size };
	for (auto i{ 0 }; i < section_size; ++i)
	{
		_thread_sum[section_num] += array[start_index + i];
	}
	_sum += _thread_sum[section_num];
}

