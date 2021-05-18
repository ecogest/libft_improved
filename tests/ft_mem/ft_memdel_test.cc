/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_test.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:36:30 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:38:25 by mjacq            ###   ########.fr       */
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

TEST(FtMemdel, all) {
	char	*s = strdup("hello");
	ft_memdel(&s);
	EXPECT_EQ(s, (char *)NULL);
	ft_memdel(&s);
	EXPECT_EQ(s, (char *)NULL);
	ft_memdel(NULL);
}
