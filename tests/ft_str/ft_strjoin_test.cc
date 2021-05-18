/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:10:47 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 20:28:43 by mjacq            ###   ########.fr       */
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

class FtStrjoinParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, const char *>>
{
public:
	const char	*s1 = std::get<0>(GetParam());
	const char	*s2 = std::get<1>(GetParam());
	char		*ret_mine;
	char		*ret_cmp;
	FtStrjoinParamTest () {
		ret_mine = ft_strjoin(s1, s2);
		if (s1 && s2) {
			ret_cmp = (char *)malloc(strlen(s2) + strlen(s1) + 1);
			strcpy(ret_cmp, s1);
			strcat(ret_cmp, s2);
		}
		else
			ret_cmp = NULL;
	}
	virtual ~FtStrjoinParamTest () {
		free(ret_mine);
		free(ret_cmp);
	}

private:
};

TEST_P(FtStrjoinParamTest, all) {
	if (s1 && s2)
		EXPECT_STREQ(ret_mine, ret_cmp);
	else
		EXPECT_EQ(ret_mine, ret_cmp);
}

#define P std::make_tuple<const char *, const char *>

INSTANTIATE_TEST_SUITE_P(FtStrjoinTestParameters, FtStrjoinParamTest,
		::testing::Values(
			P("", ""),
			P("", "a"),
			P("A", ""),
			P("", "hello"),
			P("world", ""),
			P("hello", "world"),
			P("trololo", "w💀orld"),
			P("hello", (const char *)NULL),
			P((const char *)NULL, "hello"),
			P((const char *)NULL, (const char *)NULL)
	));
