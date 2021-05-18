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

struct FtStrcatParamTest: public ::testing::TestWithParam<std::tuple<const char *, const char *>> {
	const char	*src = std::get<0>(GetParam());
	const char	*dst = std::get<1>(GetParam());
	char		dest_mine[20];
	char		dest_system[20];
	char		*ret_mine;
	char		*ret_system;
	FtStrcatParamTest() {
		// bzero(dest_mine, 20);
		// bzero(dest_system, 20);
		memset(dest_mine, 'x', 20);
		memset(dest_system, 'x', 20);
		dest_mine[19] = '\0';
		dest_system[19] = '\0';
		strcpy(dest_mine, dst);
		strcpy(dest_system, dst);
		ret_mine = ft_strcat(dest_mine, src);
		if (src)
			ret_system = strcat(dest_system, src);
	}
	~FtStrcatParamTest() {
	}
};

TEST_P(FtStrcatParamTest, all) {
	EXPECT_STREQ(dest_mine, dest_system);
	EXPECT_EQ(dest_mine, ret_mine);
	EXPECT_EQ(dest_system, ret_system);
}

#define P std::make_tuple<const char *, const char *>

INSTANTIATE_TEST_SUITE_P(FtStrcatTestParameters, FtStrcatParamTest, ::testing::Values(
			P("", ""), P("", "a"), P("A", ""), P("", "hello"), P("world", ""),
			P("hello", "world"), P("trololo", "w💀orld")
			));

/*
** =============================== NULL Cases =============================== **
*/

TEST(FtStrcatTest, NullCases) {
	char	dest[10] = "yo";
	EXPECT_EQ(ft_strcat(dest, NULL), (char *)NULL);
	EXPECT_STREQ(dest, "yo");
	EXPECT_EQ(ft_strcat(NULL, "hello"), (char *)NULL);
	EXPECT_EQ(ft_strcat(NULL, NULL), (char *)NULL);
}
