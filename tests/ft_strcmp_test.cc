/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:51 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 19:20:49 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

TEST(strcmp, basicString) {
	char *str;
	str = strdup("Hello");
	ASSERT_EQ(ft_strcmp(str, "Hello"), strcmp(str, "Hello"));
	free(str);
}
