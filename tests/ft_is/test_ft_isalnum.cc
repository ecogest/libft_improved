/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:14:47 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/06 19:56:38 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <vector>

/*
** ============================== Expect True =============================== **
*/

struct ExpectTrueTest: public ::testing::TestWithParam<char> {
};

TEST_P(ExpectTrueTest, all) {
	EXPECT_EQ(ft_isalnum(GetParam()), 1);
}

INSTANTIATE_TEST_SUITE_P(ExpectTrueSuiteNumbers, ExpectTrueTest, ::testing::Values(
			'0', '1', '2', '5', '9'));

INSTANTIATE_TEST_SUITE_P(ExpectTrueSuiteLetters, ExpectTrueTest, ::testing::Values(
			'a', 'b', 'A', 'B', 'j', 'J', 'z', 'Z'));

/*
** ============================== Expect False ============================== **
*/

struct ExpectFalseTest: public ::testing::TestWithParam<char> {
};

TEST_P(ExpectFalseTest, all) {
	EXPECT_EQ(ft_isalnum(GetParam()), 0);
}

INSTANTIATE_TEST_SUITE_P(ExpectFalseSuiteNumbers, ExpectFalseTest, ::testing::Values(
			' ', '*', '#', '!', '\n'));

/*
** =============================== Char tests =============================== **
*/

struct IsAlnumTest: public ::testing::TestWithParam<std::tuple<char, bool>> {
	char	tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IsAlnumTest, all) {
	EXPECT_EQ(ft_isalnum(tested_char), expected_result);
	EXPECT_EQ(ft_isalnum(tested_char), isalnum(tested_char));
}

INSTANTIATE_TEST_SUITE_P(AlnumSuite, IsAlnumTest, ::testing::Values(
			// False:
			std::make_tuple(' ', false),
			std::make_tuple('!', false),
			std::make_tuple('@', false),
			std::make_tuple('\n', false),
			// True:
			std::make_tuple('a', true),
			std::make_tuple('A', true),
			std::make_tuple('b', true),
			std::make_tuple('B', true),
			std::make_tuple('j', true),
			std::make_tuple('J', true),
			std::make_tuple('z', true),
			std::make_tuple('Z', true),
			std::make_tuple('0', true),
			std::make_tuple('1', true),
			std::make_tuple('2', true),
			std::make_tuple('5', true),
			std::make_tuple('9', true)
			));

/*
** =============================== Int tests ================================ **
*/

struct IntIsAlnumTest: public ::testing::TestWithParam<std::tuple<int, bool>> {
	int		tested_char = std::get<0>(GetParam());
	bool	expected_result = std::get<1>(GetParam());
};

TEST_P(IntIsAlnumTest, all) {
	EXPECT_EQ(ft_isalnum(tested_char), expected_result);
	EXPECT_EQ(ft_isalnum(tested_char), isalnum(tested_char));
}

INSTANTIATE_TEST_SUITE_P(AlnumSuite, IntIsAlnumTest, ::testing::Values(
			// False:
			std::make_tuple(0, false),
			std::make_tuple(1, false),
			std::make_tuple(126, false),
			std::make_tuple(127, false),
			std::make_tuple(128, false),
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
