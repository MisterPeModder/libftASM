/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:27:34 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/13 19:00:33 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "tests.h"

static const char	*g_data = "This is the source string, everything is in it.";
static const int	g_proc[] = {0, 5, 20, 40, 46, -1};

static size_t		expected(size_t exp, size_t res)
{
	printf(" - expected: %zu\n", exp);
	printf(" - got: %zu\n", res);
	fflush(stdout);
	return (res);
}

int					ft_strlen_test(void)
{
	const int		*i;
	size_t			exp;
	size_t			res;

	i = g_proc;
	printf("source string: \"%s\"\n", g_data);
	while (*i != -1)
	{
		printf("checking at index %d:\n", *i);
		exp = strlen(g_data + *i);
		res = expected(exp, ft_strlen(g_data + *i));
		if (res != exp)
			return (0);
		++i;
	}
	fputs("checking ft_strlen(\"\"):\n", stdout);
	res = expected(0, ft_strlen(""));
	return (!res);
}
