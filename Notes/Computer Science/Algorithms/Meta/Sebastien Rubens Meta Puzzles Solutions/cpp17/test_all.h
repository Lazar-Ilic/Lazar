// meta_puzzles by Sebastien Rubens
//
// Please go to https://github.com/seb-pg/meta_puzzles/README.md
// for more information
//
// To the extent possible under law, the person who associated CC0 with
// meta_puzzles has waived all copyright and related or neighboring rights
// to meta_puzzles.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

#pragma once

#include <stddef.h>  // size_t
#include <cmath>  // abs
#include <cstdint>  // int**_t
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <vector>
#include <utility>

template<typename _Args, typename _Ret>
struct NamedTests
{
	std::string name;
	std::vector<std::pair<_Args, _Ret>> tests;
};

template<typename _Args, typename _Ret, typename _Fn>
auto run_all_tests(const std::string& module_name,
	const std::vector<NamedTests<_Args, _Ret>>& list_of_tests, _Fn fn, double precision=0.0)
{
	static_assert(std::is_same_v<_Ret, std::invoke_result_t<_Fn, _Args&>>);  // Would prefer to use a (C++20) concept

	auto prev_precision = std::cout.precision(std::numeric_limits<double>::max_digits10);
	uint32_t nb_errors = 0;
	for (const auto& [name, tests] : list_of_tests)
	{
		std::cout << std::endl << module_name << " " << name << std::endl;
		uint32_t nb = 1;
		for (const auto& [cargs, expected] : tests)
		{
			auto args = cargs;  // copy, because Meta's functions' parameters are not const
			auto res = fn(args);

			bool is_same = true;
			if constexpr (std::is_same_v<double, _Ret> || std::is_same_v<float, _Ret>)
				is_same = std::abs(res - expected) <= precision;
			else
				is_same = res == expected;

			std::cout << "  " << name << ", test #" << nb << ": ";
			if (is_same)
			{
				std::cout << "res=" << res << " CORRECT" << std::endl;
			}
			else
			{
				++nb_errors;
				std::cout << "res=" << res << " expected=" << expected << " ERROR <-----" << std::endl;
			}
			++nb;
		}
	}
	std::cout.precision(prev_precision);
	return nb_errors;
}


// End
