#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <climits>
#include <iostream>
#include <vector>
#include <tuple>

/*
** =========================== Parametrized Tests =========================== **
*/

struct FtStrncmpParamTest: public ::testing::TestWithParam<std::tuple<const char *, const char *, size_t>> {
	int	ret_mine;
	int	ret_system;
	FtStrncmpParamTest() {
		const char *s1 = std::get<0>(GetParam());
		const char *s2 = std::get<1>(GetParam());
		size_t		n = std::get<2>(GetParam());
		ret_mine = ft_strncmp(s1, s2, n);
		ret_system = strncmp(s1, s2, n);
	}
	~FtStrncmpParamTest() {
	}
};

TEST_P(FtStrncmpParamTest, all) {
	EXPECT_EQ(ret_mine, ret_system); // Returns a pointer in haystack, not a copy (-> expect eq ptr)
}

#define P std::make_tuple<const char *, const char *, size_t>

INSTANTIATE_TEST_SUITE_P(FtStrncmpTestParameters, FtStrncmpParamTest, ::testing::Values(
			/* Match */
			P("a", "a", 1),
			P("a", "a", 2),
			P("a", "a", 0),
			P("hello", "hello", -1),
			P("hello", "hello", 0),
			P("hello", "hello", 1),
			P("hello", "hello", 2),
			P("hello", "hello", 3),
			P("hello", "hello", 4),
			P("hello", "hello", 5),
			P("hello", "hello", 6),
			P("hello", "hellO", 0),
			P("hello", "hellO", 1),
			P("hello", "hellO", 2),
			P("hello", "hellO", 3),
			P("hello", "hellO", 4),
			P("hello world", "hello world", 1),
			P("hello world", "hello world", 5), 
			P("hello world", "hello world", 10), 
			P("hello world", "hello world", 142), 
			P("hello world", "hello world", -1), 
			P("Hello world", "Hello", 5),
			P("hello w💀orld", "hello w💀orld", 42),
			P("hello w💀Orld", "hello w💀Orld", 12),
			P("yoloyolo", "yoloyolo", 4), 
			P("💀", "💀", 1),
			P("💀", "💀", 3),
			P("💀", "💀", 12),
			/* No match */
			P("a", "A", 1),
			P("A", "a", 3),
			P("hello", "hellO", 5),
			P("hello", "hellO", 6),
			P("hello", "hellO", -1),
			P("hello world", "hello", 6), 
			P("heLlo world", "hello world", 42), 
			P("hello world", "ello world", 42), 
			P("hello world", "lo", 3), 
			P("yoloyolo", "yoloyololo", 42), 
			P("hello w💀orld", "💀", 12),
			/* Empty values */
			P("hello world", "", 1),
			P("", "yo", 2),
			P("", "", 3),
			/* Wierd cases */
			P("a", "a", 0),
			P("yo", "a", 0)
			/* NULL Cases */
			// No NULL case test since strncmp is expected to segfault
			)
		);
