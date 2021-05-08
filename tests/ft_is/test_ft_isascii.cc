/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:37:38 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 07:59:33 by mrgittes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
#include <limits.h>
}

#include <vector>

/*
** =============================== Char tests =============================== **
*/

struct IsAsciiTest: public ::testing::TestWithParam<std::tuple<char, bool>> {
	char	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IsAsciiTest, all) {
	EXPECT_EQ(ft_isascii(tested_char), expected_result);
	EXPECT_EQ(ft_isascii(tested_char), isascii(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsAsciiSuite, IsAsciiTest, ::testing::Values(
			// False:
			std::make_tuple(128, false),
			std::make_tuple(-1, false),
			std::make_tuple(-42, false),
			std::make_tuple(142, false),
			// True:
			std::make_tuple(' ', true),
			std::make_tuple('!', true),
			std::make_tuple('@', true),
			std::make_tuple('\n', true),
			std::make_tuple('0', true),
			std::make_tuple('1', true),
			std::make_tuple('2', true),
			std::make_tuple('5', true),
			std::make_tuple('9', true),
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

struct IntIsAsciiTest: public ::testing::TestWithParam<std::tuple<int, bool>> {
	int	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IntIsAsciiTest, all) {
	EXPECT_EQ(ft_isascii(tested_char), expected_result);
	EXPECT_EQ(ft_isascii(tested_char), isascii(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsAsciiSuite, IntIsAsciiTest, ::testing::Values(
			// False:
			std::make_tuple(0, true),//nul
			std::make_tuple(1, true),//soh
			std::make_tuple(126, true),//~
			std::make_tuple(127, true),//del
			std::make_tuple(128, false),//not ascii
			std::make_tuple(129, false),
			std::make_tuple(1442, false),
			std::make_tuple(-442, false),
			std::make_tuple(INT_MAX, false),
			std::make_tuple(INT_MAX - 1, false),
			std::make_tuple(INT_MAX - 2, false),
			std::make_tuple(INT_MIN, false),
			std::make_tuple(INT_MIN + 1, false),
			std::make_tuple(INT_MIN + 2, false),
			std::make_tuple(L'é', false),
			// True:
			std::make_tuple(42, true),// '*'
			std::make_tuple(65, true)// 'A'
			));
