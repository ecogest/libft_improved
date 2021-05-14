/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:51 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/14 16:51:07 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

/*
** =========================== Parametrized Tests =========================== **
*/

struct FtStrcmpParamTest: public ::testing::TestWithParam<std::tuple<const char *, const char *>> {
	int	ret_mine;
	int	ret_system;
	FtStrcmpParamTest() {
		const char *s1 = std::get<0>(GetParam());
		const char *s2 = std::get<1>(GetParam());
		ret_mine = ft_strcmp(s1, s2);
		ret_system = strcmp(s1, s2);
	}
	~FtStrcmpParamTest() {
	}
};

TEST_P(FtStrcmpParamTest, all) {
	EXPECT_EQ(ret_mine, ret_system); // Returns a pointer in haystack, not a copy (-> expect eq ptr)
}

#define P std::make_tuple<const char *, const char *>

INSTANTIATE_TEST_SUITE_P(FtStrcmpTestParameters, FtStrcmpParamTest, ::testing::Values(
			/* Match */
			P("a", "a"),
			P("hello world", "hello world"), 
			P("Hello world", "Hello world"), 
			P("hello w💀orld", "hello w💀orld"),
			P("hello w💀Orld", "hello w💀Orld"),
			P("yoloyolo", "yoloyolo"), 
			P("💀", "💀"),
			/* No match */
			P("a", "A"),
			P("A", "a"),
			P("hello world", "hello"), 
			P("hello world", "ello world"), 
			P("hello world", "hEllo world"), 
			P("hello world", "lo"), 
			P("yoloyolo", "yoloyololo"), 
			P("hello w💀orld", "💀"),
			/* Empty values */
			P("hello world", ""),
			P("", "yo"),
			P("", "")
			/* NULL Cases */
			// No NULL case test since strcmp is expected to segfault
			)
		);
