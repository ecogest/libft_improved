/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend_test.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:22:17 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/19 11:41:14 by mjacq            ###   ########.fr       */
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

class FtStrappendParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, const char *>>
{
public:
	const char	*s1_cst = std::get<0>(GetParam());
	char		*s1 = ft_strdup(std::get<0>(GetParam()));
	const char	*s2 = std::get<1>(GetParam());
	char		*ret_mine;
	char		*ret_cmp;
	FtStrappendParamTest () {
		ret_mine = ft_strappend(&s1, s2);
		if (s1_cst && s2) {
			ret_cmp = (char *)malloc(strlen(s2) + strlen(s1_cst) + 1);
			strcpy(ret_cmp, s1_cst);
			strcat(ret_cmp, s2);
		}
		else
			ret_cmp = NULL;
	}
	virtual ~FtStrappendParamTest () {
		free(s1);
		free(ret_cmp);
	}

private:
};

TEST_P(FtStrappendParamTest, all) {
	if (s1 && s2)
	{
		EXPECT_STREQ(ret_mine, ret_cmp);
		EXPECT_EQ(ret_mine, s1);
	}
	else
		EXPECT_EQ(ret_mine, ret_cmp);
}

#define P std::make_tuple<const char *, const char *>

INSTANTIATE_TEST_SUITE_P(FtStrappendTestParameters, FtStrappendParamTest,
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
