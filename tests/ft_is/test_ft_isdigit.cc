/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:58:06 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 07:58:37 by mrgittes         ###   ########.fr       */
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

struct IsDigitTest: public ::testing::TestWithParam<std::tuple<char, bool>> {
	char	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IsDigitTest, all) {
	EXPECT_EQ(ft_isdigit(tested_char), expected_result);
	EXPECT_EQ(ft_isdigit(tested_char), isdigit(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsDigitSuite, IsDigitTest, ::testing::Values(
			// False:
			std::make_tuple(128, false),
			std::make_tuple(-1, false),
			std::make_tuple(-42, false),
			std::make_tuple(142, false),
			std::make_tuple(' ', false),
			std::make_tuple('!', false),
			std::make_tuple('@', false),
			std::make_tuple('\n', false),
			std::make_tuple('a', false),
			std::make_tuple('A', false),
			std::make_tuple('b', false),
			std::make_tuple('B', false),
			std::make_tuple('j', false),
			std::make_tuple('J', false),
			std::make_tuple('z', false),
			std::make_tuple('Z', false),
			// True:
			std::make_tuple('0', true),
			std::make_tuple('1', true),
			std::make_tuple('2', true),
			std::make_tuple('5', true),
			std::make_tuple('9', true)
			));

/*
** =============================== Int tests ================================ **
*/

struct IntIsDigitTest: public ::testing::TestWithParam<std::tuple<int, bool>> {
	int	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IntIsDigitTest, all) {
	EXPECT_EQ(ft_isdigit(tested_char), expected_result);
	EXPECT_EQ(ft_isdigit(tested_char), isdigit(tested_char));
}

INSTANTIATE_TEST_SUITE_P(IsDigitSuite, IntIsDigitTest, ::testing::Values(
			// False:
			std::make_tuple(0, false),//nul
			std::make_tuple(1, false),//soh
			std::make_tuple(126, false),//~
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
			std::make_tuple(42, false),// '*'
			std::make_tuple(65, false),// 'A'
			std::make_tuple(47, false),// '/'
			std::make_tuple(58, false),// ':'
			// True:
			std::make_tuple(48, true),// '0'
			std::make_tuple(57, true)// '9'
			));
