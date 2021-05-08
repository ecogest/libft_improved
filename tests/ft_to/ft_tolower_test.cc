/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:32:01 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 18:37:08 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

struct	ToLowerTest: public ::testing::TestWithParam<int> {
	int	input = GetParam();
};

TEST_P(ToLowerTest, tests) {
	EXPECT_EQ(ft_tolower(input), tolower(input));
}

INSTANTIATE_TEST_SUITE_P(ToLowerSuite, ToLowerTest, ::testing::Range(-10, 258));
INSTANTIATE_TEST_SUITE_P(ToLowerSuite2, ToLowerTest, ::testing::Values(
			INT_MIN, INT_MIN + 1, INT_MIN + 2,
			INT_MAX, INT_MAX - 1, INT_MAX - 2
			));
