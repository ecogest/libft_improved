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

struct FtSubstrParamTest: public ::testing::TestWithParam<std::tuple<const char *, unsigned int, size_t, const char *>> {
	const char		*test_input = std::get<0>(GetParam());
	unsigned int	start = std::get<1>(GetParam());
	size_t			len = std::get<2>(GetParam());
	const char		*expected_return = std::get<3>(GetParam());
	char			*ret;
	FtSubstrParamTest() {
		ret = ft_substr(test_input, start, len);
	}
	~FtSubstrParamTest() {
		free(ret);
	}
};

TEST_P(FtSubstrParamTest, all) {
	EXPECT_STREQ(ret, expected_return);
}

#define P std::make_tuple<const char *, unsigned int, size_t, const char *>

INSTANTIATE_TEST_SUITE_P(TestParameters, FtSubstrParamTest, ::testing::Values(
			/* Tests from start */
			P("hello", 0, 1, "h"),      // get first letter
			P("hello", 0, 3, "hel"),    // get till middle letter
			P("hello", 0, 5, "hello"),  // get till last letter
			P("hello", 0, 6, "hello"),  // get till '\0'
			P("hello", 0, 7, "hello"),  // get past last letter
			P("hello", 0, 42, "hello"), // get way beyond past last letter
			P("hello", 0, -1, "hello"), // get max size (using -1
			/* Tests from middle */
			P("hello", 1, 1, "e"),      // get one letter
			P("hello", 2, 1, "l"),      // get one letter
			P("hello", 4, 1, "o"),      // get one letter (last letter)
			P("hello", 5, 1, ""),       // get one letter (at '\0')
			P("hello", 6, 1, ""),       // get one letter (past end)
			P("hello", 42, 1, ""),      // get one letter (way past end)
			P("hello", 1, 3, "ell"),    // get till middle letter
			P("hello", 1, 4, "ello"),   // get till last letter
			P("hello", 1, 5, "ello"),   // get till '\0'
			P("hello", 1, 6, "ello"),   // get past last letter
			P("hello", 1, 42, "ello"),  // get way beyond past last letter
			P("hello", 1, -1, "ello"),  // get max size (using -1, ie ULONG_MAX)
			/* Misusage tests */
			P("hello", -1, 1, ""),      // negative start (~ start = UINT_MAX)
			P("hello", -1, -1, "")      // negative start and end
			));

TEST(FtSubstrTest, NullValue) {
	EXPECT_EQ(ft_substr(NULL, 1, 2), (char *)NULL);
}
