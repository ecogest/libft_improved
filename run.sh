#! /usr/bin/env bash

[ ! -d build ] && mkdir build

cd build
if cmake .. && make ; then
	[ ! -L ../compile_commands.json ] && ln -s "$PWD/compile_commands.json" ../compile_commands.json
fi
cd ..

if [ ! -f main.c ]; then
	cat > "main.c" <<'EOF'
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:32:27 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:20:06 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "libftprintf.h"
#include <fcntl.h>

int	main(void) {
	char *line;
	int	fd;

	// libft
	ft_putstr("hello!\n");
	// ft_is
	if (ft_isalpha('h'))
		ft_putstr("h is alpha\n");
	// ft_lst
	t_list *lst = ft_lstnew(NULL);
	free(lst);

	// gnl
	fd = open("./CMakeLists.txt", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	ft_putstr(line);
	ft_putchar('\n');

	// ft_printf
	ft_printf("hello %s!\n", "world");

	return (0);
}
EOF
fi

gcc -Lbuild -lft -Iincludes main.c && ./a.out
