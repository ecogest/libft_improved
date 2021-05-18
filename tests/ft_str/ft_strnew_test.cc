/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:18:33 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 19:31:24 by mjacq            ###   ########.fr       */
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

class FtStrnewParamTest:
	public ::testing::TestWithParam<int>
{
public:
	char	*str;
	char	*cmp;
	size_t size = GetParam();
	FtStrnewParamTest () {
		str = ft_strnew(size);
		cmp = (char *)malloc(size + 1);
		bzero(cmp, size + 1);
	}
	virtual ~FtStrnewParamTest () {
		free(str);
		free(cmp);
	}

private:
};

TEST_P(FtStrnewParamTest, all) {
	EXPECT_FALSE(memcmp(str, cmp, size));
}

INSTANTIATE_TEST_SUITE_P(FtStrnewTestParameters, FtStrnewParamTest,
		::testing::Values(
			0, 1, 2, 10, 42, 515
	));
