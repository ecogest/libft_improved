/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:32:54 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/17 20:22:38 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

class FtStrncpyParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, unsigned int>>
{
public:
	char		dest_mine[20];
	char		dest_system[20];
	char		*ret_mine;
	char		*ret_system;
	FtStrncpyParamTest () {
		// bzero(dest_mine, 20);
		// bzero(dest_system, 20);
		// dest is not necessarily NULL terminated, we want be sure when it does
		memset(dest_mine, 'x', 20);
		memset(dest_system, 'x', 20);
		dest_mine[19] = '\0';
		dest_system[19] = '\0';
		ret_mine = ft_strncpy(dest_mine, src, size);
		if (src)
			ret_system = strncpy(dest_system, src, size);
	}
	virtual ~FtStrncpyParamTest () {}

private:
	const char	*src = std::get<0>(GetParam());
	size_t		size = std::get<1>(GetParam());
};

TEST_P(FtStrncpyParamTest, all) {
	// EXPECT_STREQ(dest_mine, dest_system);
	EXPECT_FALSE(memcmp(dest_mine, dest_system, 20)); // watch after first '\0'
	EXPECT_EQ(dest_mine, ret_mine);
	EXPECT_EQ(dest_system, ret_system);
}

#define P std::make_tuple<const char *, unsigned int>

INSTANTIATE_TEST_SUITE_P(FtStrncpyTestParameters, FtStrncpyParamTest,
		::testing::Values(
	P("hello", 0),
	P("hello", 1),
	P("hello", 4),
	P("hello", 5),
	P("hello", 6),
	P("hello", 7),
	P("hello", 12),
	P("h", 0),
	P("h", 1),
	P("h", 4),
	P("h", 12),
	P("", 0),
	P("", 1),
	P("", 4),
	P("", 12)
	));

/*
** =============================== NULL Cases =============================== **
*/

TEST(FtStrncpyTest, NullCases) {
	char	dest[10];
	char	c;
	c = *dest;
	EXPECT_EQ(ft_strncpy(dest, NULL, 42), (char *)NULL);
	EXPECT_EQ(*dest, c);
	EXPECT_EQ(ft_strncpy(NULL, "hello", 42), (char *)NULL);
	EXPECT_EQ(ft_strncpy(NULL, NULL, 42), (char *)NULL);
}
