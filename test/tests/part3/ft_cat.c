/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 05:33:37 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 05:47:26 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "tests.h"

static int			expect(const char *path)
{
	int				fd;

	fputs("===\n===\n===\n===\n===\n", stdout);
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		printf("couldn't open data file: %s\n", strerror(errno));
		return (0);
	}
	fflush(stdout);
	ft_cat(fd);
	close(fd);
	return (1);
}

int					ft_cat_test(void)
{
	if (!expect("tests/part3/data_ft_cat.1.txt"))
		return (0);
	else if (!expect("tests/part3/data_ft_cat.2.txt"))
		return (0);
	return (1);
}
