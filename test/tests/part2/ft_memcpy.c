/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 02:27:15 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 02:35:02 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests.h"

static int			expect(size_t size, const char *src)
{
	char			*s[2];
	size_t			i;

	printf("checking with buffer size %zu and source \"%s\":\n", size, src);
	s[0] = malloc(size);
	s[1] = malloc(size);
	memcpy(s[0], src, size);
	ft_memcpy(s[1], src, size);
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
	printf(" - expected: %.*s\n - got     : %.*s\n", (int)size, s[0],
			(int)size, s[1]);
	puts(" - buffers are identical");
	free(s[0]);
	free(s[1]);
	return (1);
}

int					ft_memcpy_test(void)
{
	if (!expect(1, "E"))
		return (0);
	else if (!expect(0, "<empty> (there is nothing to see here...)"))
		return (0);
	else if (!expect(3, ">_<"))
		return (0);
	else if (!expect(4, "Test"))
		return (0);
	else if (!expect(9, "mêh mêh"))
		return (0);
	else if (!expect(16, "youpi"))
		return (0);
	else if (!expect(42, "The answer of life, the universe and everything."))
		return (0);
	return (1);
}
