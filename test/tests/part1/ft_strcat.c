/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 08:55:39 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 09:22:22 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests.h"

static size_t		alloc_strings(char **s, size_t max,
		const char *dst, const char *src)
{
	s[0] = calloc(max, sizeof(char));
	s[1] = calloc(max, sizeof(char));
	strcpy(s[0], dst);
	strcpy(s[1], dst);
	strcat(s[0], src);
	ft_strcat(s[1], src);
	return (max);
}

static int			expect(const char *dst, const char *src)
{
	size_t			max;
	char			*s[2];
	size_t			i;

	max = alloc_strings(s, strlen(dst) + strlen(src) + 42, dst, src);
	fprintf(g_logfile, "checking with \"%s\" and \"%s\"\n", dst, src);
	i = 0;
	while (i < max)
	{
		if (s[0][i] != s[1][i])
		{
			fprintf(g_logfile, " - ERROR: at offset %zu: %.2x != %.2x",
					i, s[0][i], s[1][i]);
			free(s[0]);
			free(s[1]);
			return (0);
		}
		++i;
	}
	fprintf(g_logfile, " - result: \"%s\"\n - buffers are identical\n", s[0]);
	free(s[0]);
	free(s[1]);
	return (1);
}

int					ft_strcat_test(void)
{
	if (!expect("This", " is a test"))
		return (0);
	else if (!expect("", "Hmmm"))
		return (0);
	else if (!expect("", ""))
		return (0);
	else if (!expect("Am I a lonely string ?", ""))
		return (0);
	else if (!expect("\0\0\0\0\0end ?", "Is this\0?"))
		return (0);
	return (1);
}