/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:14:07 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/13 19:39:59 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "tests.h"

static void			expect(const char *c)
{
	printf("checking with \"%s\"\n", c);
	fputs(" - expected: ", stdout);
	puts(c);
	fputs(" - got:      ", stdout);
	fflush(stdout);
	ft_puts(c);
}

int					ft_puts_test(void)
{
	fputs("NOTE: due to some technical difficulties,"
			" we cannot return the right error code\n", g_logfile);
	expect("UwU");
	expect("lorem ipsum");
	expect("Hello, World ! Hello, World ! Hello, World ! Hello, World !");
	expect("");
	return (1);
}
