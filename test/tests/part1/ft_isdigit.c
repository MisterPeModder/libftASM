/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 08:25:32 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 08:47:48 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "tests.h"

static int			expect(const char *c, int code)
{
	int				res;
	int				exp;

	fprintf(g_logfile, "checking with '%s' (U+%X):\n", c, code);
	exp = isdigit(*c);
	res = ft_isdigit(*c);
	fprintf(g_logfile, " - expected: %s\n", (res ? "true" : "false"));
	fprintf(g_logfile, " - got: %s\n", (exp ? "true" : "false"));
	fflush(g_logfile);
	return (res == exp);
}

int					ft_isdigit_test(void)
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
