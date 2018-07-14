/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 02:00:16 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 02:02:08 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests.h"

static int			expect(size_t size, int fill)
{
	char			*s[2];
	size_t			i;

	printf("checking with buffer size %zu and fill char %.2x:\n", size, fill);
	s[0] = malloc(size);
	s[1] = malloc(size);
	memset(s[0], fill, size);
	ft_memset(s[1], fill, size);
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

int					ft_memset_test(void)
{
	if (!expect(1, 'a'))
		return (0);
	else if (!expect(2, 42))
		return (0);
	else if (!expect(4, 0))
		return (0);
	else if (!expect(8, 89))
		return (0);
	else if (!expect(16, 250))
		return (0);
	else if (!expect(42, 'E'))
		return (0);
	else if (!expect(420, '9'))
		return (0);
	else if (!expect(4200, '$'))
		return (0);
	return (1);
}
