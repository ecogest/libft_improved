/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:34:43 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 19:45:47 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <climits>
#include <iostream>
#include <vector>
#include <tuple>

/*
** =========================== Parametrized Tests =========================== **
*/

class FtCallocParamTest:
	public ::testing::TestWithParam<std::tuple<size_t, size_t>>
{
public:
	char	*str;
	char	*cmp;
	size_t size = std::get<0>(GetParam());
	size_t count = std::get<1>(GetParam());
	FtCallocParamTest () {
		str = (char *)ft_calloc(count, size);
		cmp = (char *)calloc(count, size);
		bzero(cmp, size + 1);
	}
	virtual ~FtCallocParamTest () {
		free(str);
		free(cmp);
	}

private:
};

TEST_P(FtCallocParamTest, all) {
	EXPECT_FALSE(memcmp(str, cmp, (count && size ? count * size : 1)));
}

#define P std::make_tuple<size_t, size_t>

INSTANTIATE_TEST_SUITE_P(FtCallocTestParameters, FtCallocParamTest,
		::testing::Values(
			P(0, 0), P(0, 1), P(0, 2), P(0, 3), P(0, 42),
			P(1, 0), P(1, 1), P(1, 2), P(1, 3), P(1, 42),
			P(2, 0), P(2, 1), P(2, 2), P(2, 3), P(2, 42),
			P(7, 0), P(7, 1), P(7, 2), P(7, 3), P(7, 42)
	));
