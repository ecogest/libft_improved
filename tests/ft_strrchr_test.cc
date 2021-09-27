/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:19:19 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/27 14:47:02 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

/*
** =========================== Parametrized Tests =========================== **
*/

class FtStrrchrParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, int>>
{
public:
	char		*ret_mine;
	const char	*ret_system;
	FtStrrchrParamTest () {
		const char *str = std::get<0>(GetParam());
		int c = std::get<1>(GetParam());
		ret_mine = ft_strrchr(str, c);
		if (str)
			ret_system = strrchr(str, c);
		else
			ret_system = NULL; // the system strrchr segfaults on NULL entries.
		if (ret_mine)
			std::cout << ret_mine << std::endl;
	}
	virtual ~FtStrrchrParamTest () {
	}

private:
};

TEST_P(FtStrrchrParamTest, all) {
	EXPECT_EQ(ret_mine, ret_system); // Returns a pointer in haystack, not a copy (-> expect eq ptr)
}

#define P std::make_tuple<const char *, int>

INSTANTIATE_TEST_SUITE_P(FtStrrchrTestParameters, FtStrrchrParamTest,
		::testing::Values(
			/* Match */
			P("hello world", 'o'), // 2 matching chars
			P("hello world", 'l'), // 3 matching char
			P("hello world", 'h'), // 1 matching chars
			P("hello world", 'd'), // 1 matching chars
			P("hello world", ' '), // 1 matching chars
			P("hello world", '\0'), // 1 matching chars
			P("hello w💀orld", L'💀'), // 1 matching chars
			/* No Match */
			P("hello world", 'x'), // 1 matching chars
			P("hello world", -1), // 1 matching chars
			P("hello world", L'💀'), // 1 matching chars
			P("hello w😀orld", L'😃'), // 1 matching chars
			/* Empty values */
			P("", 'o'),
			/* NULL Cases */
			P(NULL, 0),
			P(NULL, 'x')
	));
