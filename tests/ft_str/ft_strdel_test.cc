/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:32:45 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:36:02 by mjacq            ###   ########.fr       */
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

TEST(FtStrdel, all) {
	char	*s = strdup("hello");
	ft_strdel(&s);
	EXPECT_EQ(s, (char *)NULL);
	ft_strdel(&s);
	EXPECT_EQ(s, (char *)NULL);
	ft_strdel(NULL);
}
