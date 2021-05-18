/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:46:57 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 17:56:42 by mjacq            ###   ########.fr       */
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

class FtStrdupParamTest:
	public ::testing::TestWithParam<const char *>
{
public:
	char		*ret;
	const char	*input = GetParam();
	FtStrdupParamTest () {
		ret = ft_strdup(input);
	}
	virtual ~FtStrdupParamTest () {
		free(ret);
	}

private:
};

TEST_P(FtStrdupParamTest, all) {
	if (input)
	{
		EXPECT_STREQ(ret, input);
		EXPECT_NE(ret, input);
	}
	else
		EXPECT_EQ(ret, (char *)NULL);
}

INSTANTIATE_TEST_SUITE_P(FtStrdupTestParameters, FtStrdupParamTest,
		::testing::Values(
			"",
			"a",
			"Ab",
			"hello world",
			"😀 😃 😄 😁 😆 😅 😂 🤣 🥲 ☺️ 😊 😇",
			"Aéfsd😀 😃 😄 😁 😆 😅 😂 🤣 🥲 ☺️ !",
			(const char *)NULL
	));
