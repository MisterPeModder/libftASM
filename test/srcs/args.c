/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:27:50 by yguaye            #+#    #+#             */
/*   Updated: 2018/06/11 08:38:39 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

static int			parse_options(const char *name, int *parse_opt,
		struct s_core *core)
{
	if (*parse_opt && name[0] == '-' && name[1] == '-')
	{
		if (!strcmp(name, "--no-colors"))
			core->use_colors = 0;
		else if (!strcmp(name, "--help"))
			return (3);
		else if (!name[2])
			*parse_opt = 0;
		else
		{
			fprintf(stderr, "Illegal option: %s\n", name);
			return (0);
		}
		return (1);
	}
	return (2);
}

static int			try_load_test(const char *name, struct s_core *core)
{
	int				ret;

	if ((ret = load_tests(name, &core->tests)) != 1)
	{
		if (ret)
			fputs("Couldn't load test: \"", stderr);
		else
			fputs("Unknown test name: \"", stderr);
		fputs(name, stderr);
		fputs("\"\n", stderr);
		return (0);
	}
	return (1);
}

int					get_args(int ac, char **av, struct s_core *core)
{
	int				parse_opt;
	int				ret;
	int				i;

	if (ac <= 1)
		return (2);
	core->use_colors = -1;
	parse_opt = 1;
	i = 0;
	while (++i < ac)
	{
		if (!(ret = parse_options(av[i], &parse_opt, core)))
			return (0);
		else if (ret == 3)
			return (3);
		else if (ret == 2 && !try_load_test(av[i], core))
			return (0);
	}
	core->use_colors = core->use_colors ? isatty(fileno(stdout)) : 0;
	return (1);
}
