/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:08:50 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/24 09:50:20 by mjacq            ###   ########.fr       */
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

static void	achar_tolower(char *achar)
{
	if (*achar >= 'A' && *achar <= 'Z')
		*achar = (*achar - 'A' + 'a');
}

/*
** =========================== Parametrized Tests =========================== **
*/

class FtStriterParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, void (*)(char *), const char *>>
{
	public:
		char	*string = ft_strdup(std::get<0>(GetParam()));
		void	(*f)(char *) = std::get<1>(GetParam());
		const char	*expected = std::get<2>(GetParam());
		FtStriterParamTest () {
			ft_striter(string, f);
		}
		virtual ~FtStriterParamTest () {
			free(string);
		}

	private:
};

TEST_P(FtStriterParamTest, all) {
	EXPECT_STREQ(string, expected);
}

#define P std::make_tuple<const char *, void (*)(char *), const char *>

INSTANTIATE_TEST_SUITE_P(FtStriterTestParameters, FtStriterParamTest,
		::testing::Values(
			P("Hello", achar_tolower, "hello"),
			P("HEllO", achar_tolower, "hello"),
			P("hello", achar_tolower, "hello"),
			P("H", achar_tolower, "h"),
			P("h", achar_tolower, "h"),
			P("dsAfJ 432 fD 👻sfD32*/-+±X	F", achar_tolower, "dsafj 432 fd 👻sfd32*/-+±x	f"),
			P("", achar_tolower, "")
	));

TEST(FtStriterTest, nullNoCrash)
{
	char	*s;

	s = NULL;
	ft_striter(s, achar_tolower);
	EXPECT_EQ(s, nullptr);
}
