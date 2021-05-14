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

struct FtStrcpyParamTest: public ::testing::TestWithParam<const char *> {
	const char	*src = GetParam();
	char		dest_mine[20];
	char		dest_system[20];
	char		*ret_mine;
	char		*ret_system;
	FtStrcpyParamTest() {
		bzero(dest_mine, 20);
		bzero(dest_system, 20);
		ret_mine = ft_strcpy(dest_mine, src);
		if (src)
			ret_system = strcpy(dest_system, src);
	}
	~FtStrcpyParamTest() {
	}
};

TEST_P(FtStrcpyParamTest, all) {
	EXPECT_STREQ(dest_mine, dest_system);
	EXPECT_EQ(dest_mine, ret_mine);
	EXPECT_EQ(dest_system, ret_system);
}

INSTANTIATE_TEST_SUITE_P(TestParameters, FtStrcpyParamTest, ::testing::Values(
			"", "a", "aB", "Hello", "Héllo w💀orld"
			));

/*
** =============================== NULL Cases =============================== **
*/

TEST(FtStrcpyTest, NullCases) {
	char	dest[10];
	char	c;
	c = *dest;
	EXPECT_EQ(strcpy(dest, NULL), (char *)NULL);
	EXPECT_EQ(*dest, c);
	EXPECT_EQ(strcpy(NULL, "hello"), (char *)NULL);
	EXPECT_EQ(strcpy(NULL, NULL), (char *)NULL);
}
