/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.cc                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:56:25 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/07 11:07:22 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
#include "stdlib.h"
}

struct AtoiTest: public ::testing::TestWithParam<const char *> {
	const char *input = GetParam();
};

TEST_P(AtoiTest, tests) {
	EXPECT_EQ(ft_atoi(input), atoi(input));
}

INSTANTIATE_TEST_SUITE_P(AtoiTestSuite, AtoiTest, testing::Values(
			"0", "1", "2", "-1", "-2",
			"2147483646", "2147483647", "2147483648", "2147483649",
			"-2147483646", "-2147483647", "-2147483648", "-2147483649"
			));
