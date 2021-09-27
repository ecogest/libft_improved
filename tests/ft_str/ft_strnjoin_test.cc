/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_test.cc                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:27:58 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/19 12:35:47 by mjacq            ###   ########.fr       */
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

class FtStrnjoinParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, const char *, size_t>>
{
public:
	const char	*s1 = std::get<0>(GetParam());
	const char	*s2 = std::get<1>(GetParam());
	char		*ret_mine;
	char		*ret_cmp;
	FtStrnjoinParamTest () {
		ret_mine = ft_strnjoin(s1, s2, size);
		if (s1 && s2) {
			ret_cmp = (char *)malloc(strlen(s2) + strlen(s1) + 1);
			strcpy(ret_cmp, s1);
			strncat(ret_cmp, s2, size);
		}
		else
			ret_cmp = NULL;
	}
	virtual ~FtStrnjoinParamTest () {
		free(ret_mine);
		free(ret_cmp);
	}

private:
	size_t		size = std::get<2>(GetParam());
};

TEST_P(FtStrnjoinParamTest, all) {
	if (s1 && s2)
		EXPECT_STREQ(ret_mine, ret_cmp);
	else
		EXPECT_EQ(ret_mine, ret_cmp);
}

#define P std::make_tuple<const char *, const char *, size_t>

INSTANTIATE_TEST_SUITE_P(FtStrnjoinTestParameters, FtStrnjoinParamTest,
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
			P("", "", 12),
			P("hello", (const char *)NULL, 42),
			P((const char *)NULL, "hello", 42),
			P((const char *)NULL, (const char *)NULL, 42)
	));