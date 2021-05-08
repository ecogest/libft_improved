/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:04:05 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 19:25:12 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <tuple>

extern "C" {
#include "libft.h"
#include <wchar.h>
}

struct	WctombTest: public ::testing::TestWithParam<std::tuple<const char *, wchar_t>> {
	char	output[5]; // we want it to be null terminated so we add one last char for the las '\0'
	const char	*expected;
	wchar_t	input;
	WctombTest(): output (), expected (std::get<0>(GetParam())), input (std::get<1>(GetParam())) {
		ft_wctomb(output, input);
	}
};

TEST_P(WctombTest, tests) {
	EXPECT_STREQ(output, expected);
}

INSTANTIATE_TEST_SUITE_P(WctombSuite, WctombTest, testing::Values(
			std::make_tuple("é", L'é'),
			std::make_tuple("🌺", L'🌺'),
			std::make_tuple("e", L'e'),
			std::make_tuple("元", L'元'),
			std::make_tuple("人", L'人'),
			std::make_tuple("ᠳ", L'ᠳ'),
			std::make_tuple("🤯", L'🤯'),
			std::make_tuple("🎃", L'🎃'),
			std::make_tuple("🥳", L'🥳'),
			std::make_tuple("!", L'!'),
			std::make_tuple("A", L'A'),
			std::make_tuple("Z", L'Z'),
			std::make_tuple("À", L'À'),
			std::make_tuple("à", L'à')
			));
