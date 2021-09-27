/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.cc                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:50:02 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/27 11:00:56 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

static void	achar_toloweri(unsigned int i, char *achar)
{
	if (i % 2 == 0 && *achar >= 'A' && *achar <= 'Z')
		*achar = (*achar - 'A' + 'a');
}

/*
** =========================== Parametrized Tests =========================== **
*/

class FtStriteriParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, void (*)(unsigned int, char *), const char *>>
{
	public:
		char	*string = ft_strdup(std::get<0>(GetParam()));
		void	(*f)(unsigned int, char *) = std::get<1>(GetParam());
		const char	*expected = std::get<2>(GetParam());
		FtStriteriParamTest () {
			ft_striteri(string, f);
		}
		virtual ~FtStriteriParamTest () {
			free(string);
		}

private:
};

TEST_P(FtStriteriParamTest, all) {
	EXPECT_STREQ(string, expected);
}

#define P std::make_tuple<const char *, void (*)(unsigned int, char *), const char *>

INSTANTIATE_TEST_SUITE_P(FtStriteriTestParameters, FtStriteriParamTest,
		::testing::Values(
			P("Hello", achar_toloweri, "hello"),
			P("hEllo", achar_toloweri, "hEllo"),
			P("HELlo", achar_toloweri, "hEllo"),
			P("hellO", achar_toloweri, "hello"),
			P("H", achar_toloweri, "h"),
			P("h", achar_toloweri, "h"),
			P("dsAfJ 432 fD 👻sfd32*/-+±x	f", achar_toloweri, "dsafj 432 fD 👻sfd32*/-+±x	f"), // careful with the index after a non ascii char
			P("", achar_toloweri, "")
	));

TEST(FtStriteriTest, nullNoCrash)
{
	char	*s;

	s = NULL;
	ft_striteri(s, achar_toloweri);
	EXPECT_EQ(s, nullptr);
}
