/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:25:18 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 10:03:19 by mjacq            ###   ########.fr       */
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

class FtStrlcpyParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, size_t>>
{
public:
	char		dest_mine[20];
	char		dest_system[20];
	size_t		ret_mine;
	size_t		ret_system;
	FtStrlcpyParamTest () {
		memset(dest_mine, 'x', 20);
		memset(dest_system, 'x', 20);
		dest_mine[19] = '\0';
		dest_system[19] = '\0';
		ret_mine = ft_strlcpy(dest_mine, src, size);
		if (src)
			ret_system = strlcpy(dest_system, src, size);
	}
	virtual ~FtStrlcpyParamTest () {
	}

private:
	const char	*src = std::get<0>(GetParam());
	size_t		size = std::get<1>(GetParam());
};

TEST_P(FtStrlcpyParamTest, all) {
	// EXPECT_STREQ(dest_mine, dest_system);
	EXPECT_FALSE(memcmp(dest_mine, dest_system, 20)); // watch after first '\0'
	EXPECT_EQ(ret_mine, ret_system);
}

#define P std::make_tuple<const char *, size_t>

INSTANTIATE_TEST_SUITE_P(FtStrlcpyTestParameters, FtStrlcpyParamTest,
		::testing::Values(
	P("hello", 0),
	P("hello", 1),
	P("hello", 4),
	P("hello", 5),
	P("hello", 6),
	P("hello", 7),
	P("hello", 12),
	P("hello", -1),
	P("h", 0),
	P("h", 1),
	P("h", 4),
	P("h", 12),
	P("h", -1),
	P("", 0),
	P("", 1),
	P("", 4),
	P("", 12),
	P("", -1)
	));

/*
** =============================== NULL Cases =============================== **
*/

TEST(FtStrlcpyTest, NullCases) {
	char	dest[10];
	char	c;
	*dest = 'X';
	c = *dest;
	EXPECT_EQ(ft_strlcpy(dest, NULL, 42), 0);
	EXPECT_EQ(*dest, c);
	EXPECT_EQ(ft_strlcpy(NULL, "hello", 42), 0);
	EXPECT_EQ(ft_strlcpy(NULL, NULL, 42), 0);
}
