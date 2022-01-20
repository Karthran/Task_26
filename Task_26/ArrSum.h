#pragma once
#include <vector>
#include <thread>
class ArrSum
{
public:
	ArrSum(){};
	auto calcSum(const std::vector<int>& array, size_t section_num)->void;
	auto getSum() -> long long { return _sum; }

private:
	size_t _array_size{};
	size_t _section_num{};
	std::vector<std::thread> threads{};
	std::vector<int> _thread_sum{};
	long long _sum{ 0 };
	auto section_sum(const std::vector<int>& array, size_t section_num, size_t section_size)->void;
};

