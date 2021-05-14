/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:15:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/14 14:46:43 by mjacq            ###   ########.fr       */
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

struct FtStrchrParamTest: public ::testing::TestWithParam<std::tuple<const char *, int>> {
	char		*ret_mine;
	const char	*ret_system;
	FtStrchrParamTest() {
		const char *str = std::get<0>(GetParam());
		int c = std::get<1>(GetParam());
		ret_mine = ft_strchr(str, c);
		if (str)
			ret_system = strchr(str, c);
		else
			ret_system = NULL; // the system strchr segfaults on NULL entries.
		if (ret_mine)
			std::cout << ret_mine << std::endl;
	}
	~FtStrchrParamTest() {
	}
};

TEST_P(FtStrchrParamTest, all) {
	EXPECT_EQ(ret_mine, ret_system); // Returns a pointer in haystack, not a copy (-> expect eq ptr)
}

#define P std::make_tuple<const char *, int>

INSTANTIATE_TEST_SUITE_P(FtStrchrTestParameters, FtStrchrParamTest, ::testing::Values(
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
