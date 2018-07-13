/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 01:24:58 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 01:36:54 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests.h"

static int			expect(size_t size)
{
	char			*s[2];
	size_t			i;

	printf("checking with buffer size %zu:\n", size);
	s[0] = malloc(size);
	s[1] = malloc(size);
	memset(s[0], 0, size);
	ft_bzero(s[1], size);
	i = 0;
	while (i < size)
	{
		if (s[0][i] != s[1][i])
		{
			printf(" - ERROR: at offset %zu: %.2x != %.2x "
					"(original != custom)\n", i, s[0][i], s[1][i]);
			free(s[0]);
			free(s[1]);
			return (0);
		}
		++i;
	}
	puts(" - buffers are identical");
	free(s[0]);
	free(s[1]);
	return (1);
}

int					ft_bzero_test(void)
{
	if (!expect(1))
		return (0);
	else if (!expect(2))
		return (0);
	else if (!expect(4))
		return (0);
	else if (!expect(8))
		return (0);
	else if (!expect(16))
		return (0);
	else if (!expect(42))
		return (0);
	else if (!expect(420))
		return (0);
	else if (!expect(4200))
		return (0);
	return (1);
}
