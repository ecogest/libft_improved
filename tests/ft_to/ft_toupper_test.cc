/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:38:06 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 18:39:12 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

struct	ToUpperTest: public ::testing::TestWithParam<int> {
	int	input = GetParam();
};

TEST_P(ToUpperTest, tests) {
	EXPECT_EQ(ft_toupper(input), toupper(input));
}

INSTANTIATE_TEST_SUITE_P(ToUpperSuite, ToUpperTest, ::testing::Range(-10, 258));
INSTANTIATE_TEST_SUITE_P(ToUpperSuite2, ToUpperTest, ::testing::Values(
			INT_MIN, INT_MIN + 1, INT_MIN + 2,
			INT_MAX, INT_MAX - 1, INT_MAX - 2
			));
