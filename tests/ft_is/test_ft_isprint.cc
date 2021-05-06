/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:04:37 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/06 20:09:16 by mjacq            ###   ########.fr       */
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

struct IsPrintTest: public ::testing::TestWithParam<std::tuple<char, bool>> {
	char	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IsPrintTest, all) {
	EXPECT_EQ(ft_isprint(tested_char), expected_result);
	EXPECT_EQ(ft_isprint(tested_char), isprint(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsPrintSuite, IsPrintTest, ::testing::Values(
			// False:
			std::make_tuple(128, false),
			std::make_tuple(-1, false),
			std::make_tuple(-42, false),
			std::make_tuple(142, false),
			std::make_tuple('\n', false),
			// True:
			std::make_tuple('0', true),
			std::make_tuple('1', true),
			std::make_tuple('2', true),
			std::make_tuple('5', true),
			std::make_tuple('9', true),
			std::make_tuple(' ', true),
			std::make_tuple('!', true),
			std::make_tuple('@', true),
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

struct IntIsPrintTest: public ::testing::TestWithParam<std::tuple<int, bool>> {
	int	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IntIsPrintTest, all) {
	EXPECT_EQ(ft_isprint(tested_char), expected_result);
	EXPECT_EQ(ft_isprint(tested_char), isprint(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsPrintSuite, IntIsPrintTest, ::testing::Values(
			// False:
			std::make_tuple(0, false),//nul
			std::make_tuple(1, false),//soh
			std::make_tuple(127, false),//del
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
			std::make_tuple(65, true),// 'A'
			std::make_tuple(47, true),// '/'
			std::make_tuple(58, true),// ':'
			std::make_tuple(126, true),//~
			std::make_tuple(48, true),// '0'
			std::make_tuple(57, true)// '9'
			));
