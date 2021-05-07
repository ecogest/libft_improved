/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.cc                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:41:22 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/07 16:58:42 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
}

struct ItoaTest: public ::testing::TestWithParam<const char *> {
	const char *expect = GetParam();
	int		input;
	char	*output;
	ItoaTest(): input (atoi(expect)), output (ft_itoa(input)) {
	}
	~ItoaTest() {
		free(output);
	}
};

TEST_P(ItoaTest, tests) {
	EXPECT_STREQ(output, expect);
	// printf("input: %d ; output: %s ", input, output);
}

INSTANTIATE_TEST_SUITE_P(ItoaTestSuite, ItoaTest, testing::Values(
			"0", "1", "2", "-1", "-2", "42", "43", "-42", "-43", "12345", "67896", // Basic
			"2147483646", "2147483647", // Close to INT_MAX
			"-2147483646", "-2147483647", "-2147483648" // Close to INT_MIN
			));
