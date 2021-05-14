#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
#include <string.h>
}

#include <climits>
#include <iostream>
#include <vector>
#include <tuple>

/*
** =========================== Parametrized Tests =========================== **
*/

struct FtStrstrParamTest: public ::testing::TestWithParam<std::tuple<const char *, const char *>> {
	char		*ret_mine;
	const char	*ret_system;
	FtStrstrParamTest() {
		const char *haystack = std::get<0>(GetParam());
		const char *needle = std::get<1>(GetParam());
		ret_mine = ft_strstr(haystack, needle);
		if (haystack && needle)
			ret_system = strstr(haystack, needle);
		else
			ret_system = NULL; // the system strstr segfaults on NULL entries.
	}
	~FtStrstrParamTest() {
	}
};

TEST_P(FtStrstrParamTest, all) {
	EXPECT_EQ(ret_mine, ret_system); // Returns a pointer in haystack, not a copy (-> expect eq ptr)
}

#define P std::make_tuple<const char *, const char *>

INSTANTIATE_TEST_SUITE_P(FtStrstrTestParameters, FtStrstrParamTest, ::testing::Values(
			/* Match */
			P("hello world", "lo"), // 2 matching chars
			P("hello world", "l"), // 1 matching char (3 places)
			P("hello world", "orl"), // 3 matching chars
			P("yoloyolo", "lo"), // 2 matching chars (2 places)
			P("yoloyolo", "yo"), // 2 matching chars on start (2 places)
			P("hello w💀orld", "💀"),
			P("hello w💀orld", "w💀"),
			P("hello w💀orld", "💀o"),
			/* No Match */
			P("hello world", "xd"), // no match
			P("hello world", "ldh"), // no match
			P("hello world", "od"), // no match with existing string characters
			P("hello world", "eh"), // idem
			P("hello world", "hello wd"), // idem
			P("hello world", " hello w"),
			P("hello w😀orld", "hello w😀"),
			/* Empty values */
			P("hello world", ""),
			P("", "yo"),
			P("", ""),
			/* NULL Cases */
			P(NULL, "fd"),
			P("ho", NULL),
			P(NULL, NULL)
			)
		);
