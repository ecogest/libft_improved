/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:53:22 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:00:17 by mjacq            ###   ########.fr       */
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

class FtStrlcatParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, const char *, size_t>>
{
public:
	char		dest_mine[20];
	char		dest_system[20];
	size_t		ret_mine;
	size_t		ret_system;
	FtStrlcatParamTest () {
		memset(dest_mine, 'x', 20);
		memset(dest_system, 'x', 20);
		strcpy(dest_mine, dst);
		strcpy(dest_system, dst);
		dest_mine[19] = '\0';
		dest_system[19] = '\0';
		ret_mine = ft_strlcat(dest_mine, src, size);
		if (src)
			ret_system = strlcat(dest_system, src, size);
	}
	virtual ~FtStrlcatParamTest () {
	}

private:
	const char	*src = std::get<0>(GetParam());
	const char	*dst = std::get<1>(GetParam());
	size_t		size = std::get<2>(GetParam());
};

TEST_P(FtStrlcatParamTest, all) {
	EXPECT_FALSE(memcmp(dest_mine, dest_system, 20)); // watch after first '\0'
	EXPECT_EQ(ret_mine, ret_system);
}

#define P std::make_tuple<const char *, const char *, size_t>

INSTANTIATE_TEST_SUITE_P(FtStrlcatTestParameters, FtStrlcatParamTest,
		::testing::Values(
	P("hello", " wo", 0),
	P("hello", " wo", 1),
	P("hello", " wo", 4),
	P("hello", " wo", 5),
	P("hello", " wo", 6),
	P("hello", " wo", 7),
	P("hello", " wo", 8),
	P("hello", " wo", 9),
	P("hello", " wo", 10),
	P("hello", " wo", 12),
	P("hello", " wo", -1),
	P("h", "ell", 0),
	P("h", "ell", 1),
	P("h", "ell", 4),
	P("h", "ell", 12),
	P("h", "", 0),
	P("h", "", 1),
	P("h", "", 2),
	P("h", "", 3),
	P("", "e", 0),
	P("", "e", 1),
	P("", "e", 2),
	P("", "e", 4),
	P("", "e", 12),
	P("", "", 0),
	P("", "", 1),
	P("", "", 12)
	));

/*
** =============================== NULL Cases =============================== **
*/

TEST(FtStrlcatTest, NullCases) {
	char	dest[10];
	char	c;
	*dest = 'X';
	c = *dest;
	EXPECT_EQ(ft_strlcat(dest, NULL, 42), 0);
	EXPECT_EQ(*dest, c);
	EXPECT_EQ(ft_strlcat(NULL, "hello", 42), 0);
	EXPECT_EQ(ft_strlcat(NULL, NULL, 42), 0);
}
