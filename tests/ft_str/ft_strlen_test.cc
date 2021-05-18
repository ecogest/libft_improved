/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:00:02 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 18:06:40 by mjacq            ###   ########.fr       */
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

class FtStrlenParamTest:
	public ::testing::TestWithParam<const char *>
{
public:
	const char	*input = GetParam();
	size_t	my_ret;
	size_t	system_ret;
	FtStrlenParamTest () {
		my_ret = ft_strlen(input);
		if (input)
			system_ret = strlen(input);
	}
	virtual ~FtStrlenParamTest () {
	}

private:
};

TEST_P(FtStrlenParamTest, all) {
	if (input)
	{
		EXPECT_EQ(my_ret, system_ret);
	}
	else
		EXPECT_EQ(my_ret, 0);
}

INSTANTIATE_TEST_SUITE_P(FtStrlenTestParameters, FtStrlenParamTest,
		::testing::Values(
			"",
			"a",
			"Ab",
			"hello world",
			"😀 😃 😄 😁 😆 😅 😂 🤣 🥲 ☺️ 😊 😇",
			"Aéfsd😀 😃 😄 😁 😆 😅 😂 🤣 🥲 ☺️ !",
			(const char *)NULL
	));
