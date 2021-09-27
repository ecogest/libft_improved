/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris_test.cc                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:19 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/27 11:21:55 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

static int	is_lower(int c) {
	return (c < 'A' || c > 'Z');
}

/*
** =========================== Parametrized Tests =========================== **
*/

class FtStrisParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, int (*)(int), bool>>
{
	public:
		const char *string = std::get<0>(GetParam());
		int	(*ft_is)(int c) = std::get<1>(GetParam());
		bool	expected_result = std::get<2>(GetParam());
		bool	output_result;
		FtStrisParamTest ()
		{
			output_result = ft_stris(string, ft_is);
		}
		virtual ~FtStrisParamTest () {
		}

private:
};

TEST_P(FtStrisParamTest, all) {
	EXPECT_EQ(expected_result, output_result);
}

#define P std::make_tuple<const char *, int (*)(int), bool>

INSTANTIATE_TEST_SUITE_P(FtStrisTestParameters, FtStrisParamTest,
		::testing::Values(
			P("hello", is_lower, true),
			P("Hello", is_lower, false),
			P("hEllo", is_lower, false),
			P("hellO", is_lower, false),
			P("h", is_lower, true),
			P("", is_lower, true),
			P("456a", is_lower, true),
			P("456A", is_lower, false)
	));

TEST(FtStrisTest, nullNoCrash)
{
	char	*s;
	bool	ret;

	s = NULL;
	ret = ft_stris(s, is_lower);
	EXPECT_EQ(s, nullptr);
	EXPECT_EQ(ret, false);
}
