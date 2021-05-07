/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa_base.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:59:57 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/07 17:41:33 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
}

struct ItoaBase10Test: public ::testing::TestWithParam<const char *> {
	const char *expect = GetParam();
	int		input;
	char	*output;
	ItoaBase10Test(): input (atoi(expect)), output (ft_itoa_base(input, 10)) {
	}
	~ItoaBase10Test() {
		free(output);
	}
};

TEST_P(ItoaBase10Test, tests) {
	EXPECT_STREQ(output, expect);
	printf("input: %d ; output: %s ", input, output);
}

INSTANTIATE_TEST_SUITE_P(ItoaBase10TestSuite, ItoaBase10Test, testing::Values(
			"0", "1", "2", "42", "43", "12345", "67896", // Basic
			"2147483646", "2147483647" // Close to INT_MAX
			));

/* ================================= Base N ================================= */

struct ItoaBaseNTest: public ::testing::TestWithParam<std::tuple<unsigned long long, int, const char *>>
{
	unsigned long long	nb;
	int					base;
	char				*output;
	const char			*expect;
	ItoaBaseNTest() {
		nb = std::get<0>(GetParam());
		base = std::get<1>(GetParam());
		expect = std::get<2>(GetParam());
		output = ft_itoa_base(nb, base);
	}
	~ItoaBaseNTest() {
		free(output);
	}
};

TEST_P(ItoaBaseNTest, tests) {
	if (!expect)
		EXPECT_EQ(output, (char *)NULL);
	else
	{
		EXPECT_STREQ(output, expect);
		printf("input: (nb:%lld, base:%d) ; output: %s ; expect: %s", nb, base, output, expect);
	}
}

INSTANTIATE_TEST_SUITE_P(ItoaBaseNSuite, ItoaBaseNTest, testing::Values(
			std::make_tuple(0, 10, "0"),
			std::make_tuple(0, 2, "0"),
			std::make_tuple(0, 7, "0"),
			std::make_tuple(0, 16, "0"),
			std::make_tuple(1, 11, "1"),
			std::make_tuple(1, 2, "1"),
			std::make_tuple(1, 7, "1"),
			std::make_tuple(1, 16, "1"),
			std::make_tuple(12, 10, "12"),
			std::make_tuple(12, 16, "C"),
			std::make_tuple(12, 2, "1100"),
			std::make_tuple(12, 3, "110"),
			std::make_tuple(0x123456789AB, 16, "123456789AB"),
			std::make_tuple(0xCDEF0CDEF0, 16, "CDEF0CDEF0"),
			std::make_tuple(UINT_MAX, 16, "FFFFFFFF"),
			std::make_tuple(LLONG_MAX, 16, "7FFFFFFFFFFFFFFF"),
			std::make_tuple(ULLONG_MAX, 16, "FFFFFFFFFFFFFFFF"),
			std::make_tuple(ULLONG_MAX - 1, 16, "FFFFFFFFFFFFFFFE"),
			// NULL
			std::make_tuple(12, 0, (const char *)NULL),
			std::make_tuple(12, 1, (const char *)NULL),
			std::make_tuple(12, 17, (const char *)NULL),
			std::make_tuple(12, 33, (const char *)NULL),
			std::make_tuple(12, -1, (const char *)NULL),
			std::make_tuple(12, -42, (const char *)NULL)
			));
