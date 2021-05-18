/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:41:06 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 15:27:41 by mjacq            ###   ########.fr       */
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

class FtStrncatParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, const char *, size_t>>
{
public:
	char		dest_mine[20];
	char		dest_system[20];
	char		*ret_mine;
	char		*ret_system;
	FtStrncatParamTest () {
		memset(dest_mine, 'x', 20);
		memset(dest_system, 'x', 20);
		strcpy(dest_mine, dst);
		strcpy(dest_system, dst);
		dest_mine[19] = '\0';
		dest_system[19] = '\0';
		ret_mine = ft_strncat(dest_mine, src, size);
		if (src)
			ret_system = strncat(dest_system, src, size);
	}
	virtual ~FtStrncatParamTest () {
	}

private:
	const char	*src = std::get<0>(GetParam());
	const char	*dst = std::get<1>(GetParam());
	size_t		size = std::get<2>(GetParam());
};

TEST_P(FtStrncatParamTest, all) {
	EXPECT_FALSE(memcmp(dest_mine, dest_system, 20)); // watch after first '\0'
	EXPECT_EQ(dest_mine, ret_mine);
	EXPECT_EQ(dest_system, ret_system);
}

#define P std::make_tuple<const char *, const char *, size_t>

INSTANTIATE_TEST_SUITE_P(FtStrncatTestParameters, FtStrncatParamTest,
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

TEST(FtStrncatTest, NullCases) {
	char	dest[10];
	char	c;
	*dest = 'X';
	c = *dest;
	EXPECT_EQ(ft_strncat(dest, NULL, 42), (char *)NULL);
	EXPECT_EQ(*dest, c);
	EXPECT_EQ(ft_strncat(NULL, "hello", 42), (char *)NULL);
	EXPECT_EQ(ft_strncat(NULL, NULL, 42), (char *)NULL);
}
