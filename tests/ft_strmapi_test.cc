/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:08:34 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/24 09:30:44 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <tuple>

static char tolower_if_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}

/*
** =========================== Parametrized Tests =========================== **
*/

class FtStrmapiParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, char (*)(unsigned int, char), const char *>>
{
public:
	const char		*string = std::get<0>(GetParam());
	char (*f)(unsigned int, char) = std::get<1>(GetParam());
	const char		*expected_return = std::get<2>(GetParam());
	char			*ret;
	FtStrmapiParamTest () {
		ret = ft_strmapi(string, f);
	}
	virtual ~FtStrmapiParamTest () {
		free(ret);
	}

private:
};

TEST_P(FtStrmapiParamTest, all) {
	EXPECT_STREQ(ret, expected_return);
}

#define P std::make_tuple<const char *, char (*)(unsigned int, char), const char *>

INSTANTIATE_TEST_SUITE_P(FtStrmapiTestParameters, FtStrmapiParamTest,
		::testing::Values(
			P("Hello", tolower_if_even, "hello"),
			P("hEllo", tolower_if_even, "hEllo"),
			P("HELlo", tolower_if_even, "hEllo"),
			P("hellO", tolower_if_even, "hello"),
			P("H", tolower_if_even, "h"),
			P("h", tolower_if_even, "h"),
			P("dsAfJ 432 fD 👻sfd32*/-+±x	f", tolower_if_even, "dsafj 432 fD 👻sfd32*/-+±x	f"), // careful with the index after a non ascii char
			P("", tolower_if_even, "")
	));

TEST(FtStrmapiTest, nullNoCrash)
{
	EXPECT_EQ(ft_strmapi(nullptr, tolower_if_even), nullptr);
}
