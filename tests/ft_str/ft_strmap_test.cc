/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:57:31 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/24 09:06:51 by mjacq            ###   ########.fr       */
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

char	tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}
/*
** =========================== Parametrized Tests =========================== **
*/

class FtStrmapParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, char (*)(char), const char *>>
{
public:
	const char		*string = std::get<0>(GetParam());
	char (*f)(char) = std::get<1>(GetParam());
	const char		*expected_return = std::get<2>(GetParam());
	char			*ret;
	FtStrmapParamTest () {
		ret = ft_strmap(string, f);
	}
	virtual ~FtStrmapParamTest () {
		free(ret);
	}

private:
};

TEST_P(FtStrmapParamTest, all) {
	EXPECT_STREQ(ret, expected_return);
}

#define P std::make_tuple<const char *, char (*)(char), const char *>

INSTANTIATE_TEST_SUITE_P(FtStrmapTestParameters, FtStrmapParamTest,
		::testing::Values(
			P("Hello", tolower, "hello"),
			P("Hello", tolower, "hello"),
			P("hello", tolower, "hello"),
			P("H", tolower, "h"),
			P("h", tolower, "h"),
			P("dsAfJ 432 fD 👻sfD32*/-+±X	F", tolower, "dsafj 432 fd 👻sfd32*/-+±x	f"),
			P("", tolower, "")
	));

TEST(FtStrmapTest, nullNoCrash)
{
	EXPECT_EQ(ft_strmap(nullptr, tolower), nullptr);
}
