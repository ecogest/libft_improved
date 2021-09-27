/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:24:23 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/27 11:59:07 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

/*
** =========================== Parametrized Tests =========================== **
*/

class FtStrnstrParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, const char *, size_t>>
{
public:
	char		*ret_mine;
	const char	*ret_system;
	FtStrnstrParamTest () {
		const char *haystack = std::get<0>(GetParam());
		const char *needle = std::get<1>(GetParam());
		size_t		len = std::get<2>(GetParam());
		ret_mine = ft_strnstr(haystack, needle, len);
		if (haystack && needle)
			ret_system = strnstr(haystack, needle, len);
		else
			ret_system = NULL; // the system strstr segfaults on NULL entries.
	}
	virtual ~FtStrnstrParamTest () {
	}

private:
};

TEST_P(FtStrnstrParamTest, all) {
	EXPECT_EQ(ret_mine, ret_system); // Returns a pointer in haystack, not a copy (-> expect eq ptr)
}

#define P std::make_tuple<const char *, const char *, size_t>

INSTANTIATE_TEST_SUITE_P(FtStrnstrTestParameters, FtStrnstrParamTest,
		::testing::Values(
			/* Match */
			P("hello world", "l", 1), // 1 matching chars
			P("hello world", "lo", 1), // 1 matching chars
			P("hello world", "lp", 1), // 1 matching chars
			P("hello world", "lo", 2), // 2 matching chars
			P("hello world", "he", 2), // 2 matching chars (on start)
			P("hello world", "ld", 2), // 2 matching chars (on end)
			P("hello world", "lo", 3), // 2 matching chars
			P("hello world", "lo", 4), // 2 matching chars
			P("hello world", "orl", 3), // 3 matching chars
			P("yoloyolo", "lo", 2), // 2 matching chars (2 places)
			P("yoloyoloa", "loa", 3), // 3 matching chars on start (2 places)
			P("hello w💀orld", "💀", 1),
			P("hello w💀orld", "💀", 2),
			P("hello w💀orld", "💀", 3),
			P("hello w💀orld", "💀", 4),
			P("hello w💀orld", "💀", 5),
			P("hello w💀orld", "w💀", 1),
			P("hello w💀orld", "w💀", 3),
			P("hello w💀orld", "💀o", 1),
			P("hello w💀orld", "💀o", 3),
			P("hello w💀orld", "💀o", 5),
			/* No Match (pas forcément, fait vite fait) */
			P("hello world", "xd", 1), // no match
			P("hello world", "eh", 2), // idem
			P("hello world", "hello wd", 16), // idem
			P("hello world", " hello w", 16),
			P("hello w😀orld", "hello w😀", 3),
			P("hello w😀orld", "hello w😀", 15),
			/* Empty values */
			P("hello world", "", 1),
			P("hello world", "", 5),
			P("", "yo", 1),
			P("", "yo", 2),
			P("", "", 1),
			P("", "", 4),
			/* NULL Cases */
			P(NULL, "fd", 1),
			P("ho", NULL, 1),
			P(NULL, NULL, 1)
	));
