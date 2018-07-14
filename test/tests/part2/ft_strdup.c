/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 03:33:10 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 03:35:58 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests.h"

static int			expect(const char *src)
{
	char			*s[2];
	size_t			i;
	size_t			size;

	size = strlen(src);
	printf("checking with source \"%s\":\n", src);
	s[0] = strdup(src);
	s[1] = ft_strdup(src);
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

int					ft_strdup_test(void)
{
	if (!expect("E"))
		return (0);
	else if (!expect("<empty> (there is nothing to see here...)"))
		return (0);
	else if (!expect(">_<"))
		return (0);
	else if (!expect("Test"))
		return (0);
	else if (!expect("mêh mêh"))
		return (0);
	else if (!expect("youpi"))
		return (0);
	else if (!expect("The answer of life, the universe and everything."))
		return (0);
	return (1);
}
