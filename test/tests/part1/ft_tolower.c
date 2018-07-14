/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:14:53 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/13 19:00:50 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "tests.h"

static int			expect(const char *c, int code)
{
	int				res;
	int				exp;

	printf("checking with '%s' (U+%X):\n", c, code);
	exp = tolower(*c);
	res = ft_tolower(*c);
	printf(" - expected: '%c' (%d)\n", (char)exp, exp);
	printf(" - got: '%c' (%d)\n", (char)res, res);
	fflush(stdout);
	return ((char)res == (char)exp);
}

int					ft_tolower_test(void)
{
	char			c[2];
	int				i;

	c[1] = 0;
	i = -1;
	while (++i < 128)
	{
		c[0] = (char)i;
		if (!expect(c, i))
			return (0);
	}
	if (!expect("é", 233))
		return (0);
	if (!expect("∆", 8710))
		return (0);
	if (!expect("😱 ", 128561))
		return (0);
	return (1);
}
