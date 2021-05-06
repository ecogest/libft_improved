/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:25:13 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/06 19:55:19 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <vector>

/*
** =============================== Char tests =============================== **
*/

struct IsAlphaTest: public ::testing::TestWithParam<std::tuple<char, bool>> {
	char	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IsAlphaTest, all) {
	EXPECT_EQ(ft_isalpha(tested_char), expected_result);
	EXPECT_EQ(ft_isalpha(tested_char), isalpha(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsAlphaSuite, IsAlphaTest, ::testing::Values(
			// False:
			std::make_tuple(' ', false),
			std::make_tuple('!', false),
			std::make_tuple('@', false),
			std::make_tuple('\n', false),
			std::make_tuple('0', false),
			std::make_tuple('1', false),
			std::make_tuple('2', false),
			std::make_tuple('5', false),
			std::make_tuple('9', false),
			// True:
			std::make_tuple('a', true),
			std::make_tuple('A', true),
			std::make_tuple('b', true),
			std::make_tuple('B', true),
			std::make_tuple('j', true),
			std::make_tuple('J', true),
			std::make_tuple('z', true),
			std::make_tuple('Z', true)
			));

/*
** =============================== Int tests ================================ **
*/

struct IntIsAlphaTest: public ::testing::TestWithParam<std::tuple<int, bool>> {
	int		tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IntIsAlphaTest, all) {
	EXPECT_EQ(ft_isalpha(tested_char), expected_result);
	EXPECT_EQ(ft_isalpha(tested_char), isalpha(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsAlphaSuite, IntIsAlphaTest, ::testing::Values(
			// False:
			std::make_tuple(0, false),//nul
			std::make_tuple(1, false),//soh
			std::make_tuple(126, false),//~
			std::make_tuple(127, false),//del
			std::make_tuple(128, false),//not ascii
			std::make_tuple(129, false),
			std::make_tuple(1442, false),
			std::make_tuple(INT_MAX, false),
			std::make_tuple(INT_MAX - 1, false),
			std::make_tuple(INT_MAX - 2, false),
			std::make_tuple(INT_MIN, false),
			std::make_tuple(INT_MIN + 1, false),
			std::make_tuple(INT_MIN + 2, false),
			std::make_tuple(42, false),// '*'
			std::make_tuple(L'é', false),
			// True:
			std::make_tuple(65, true)// 'A'
			));
