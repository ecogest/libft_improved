#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <climits>
#include <iostream>
#include <vector>
#include <tuple>

/*
** ================================ Fixture ================================= **
*/

struct FtStrtrimParamTest: public ::testing::TestWithParam<std::tuple<const char *, const char *, const char *>> {
	const char		*string = std::get<0>(GetParam());
	const char		*set = std::get<1>(GetParam());
	const char		*expected_return = std::get<2>(GetParam());
	char			*ret;
	FtStrtrimParamTest() {
		ret = ft_strtrim(string, set);
	}
	~FtStrtrimParamTest() {
		free(ret);
	}
};

TEST_P(FtStrtrimParamTest, all) {
	EXPECT_STREQ(ret, expected_return);
}

#define P std::make_tuple<const char *, const char *, const char *>

INSTANTIATE_TEST_SUITE_P(FtStrtrimTestParameters, FtStrtrimParamTest, ::testing::Values(
			/* 1 letter set */
			P("hello", "h", "ello"),      // trim first letter
			P("hello", "o", "hell"),      // trim last letter
			P("hello", "x", "hello"),      // trim nothing
			P("hhhelhloh", "h", "elhlo"),      // trim on both sides
			P(" hhhelhlohh", "h", " hhhelhlo"),      // trim on right side
			/* Multi letter set */
			P("hello world", "hdlo", "ello wor"),
			P("hello world", "low", "hello world"),
			P("hello world", "hhhhhhhhhhhhhd", "ello worl"),
			P("hello world", "oooooooiiiiiiiiiooooooooo", "hello world"),
			P("hello world", "oooooooiiiiidiiiiooooooooo", "hello worl"),
			/* empty cases */
			P("hello", "", "hello"),      // empty set
			P("", "", ""),      // empty string + empty set
			P("", "h", ""),      // empty string
			P("yolo", "yol", ""),      // trim everything
			P("yolo", "oyl", "")      // trim everything (2)
			));

TEST(FtStrtrimTest, NullValue) {
	EXPECT_EQ(ft_substr(NULL, 1, 2), (char *)NULL);
}

/*
** =============================== NULL Cases =============================== **
*/

TEST(FtStrtrimTest, NullCases)
{
	// Any NULL entry is expected to give a NULL return
	EXPECT_EQ(ft_strtrim(NULL, "x"), (char *)NULL);
	EXPECT_EQ(ft_strtrim("hello", NULL), (char *)NULL);
	EXPECT_EQ(ft_strtrim(NULL, NULL), (char *)NULL);
}
