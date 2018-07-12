/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 19:00:59 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 05:30:59 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "test.h"
#include "launchers.h"

static const struct s_launcher launchers[] =
{
	{"part1", &launcher_part1},
	{NULL, NULL}
};

static void			add_tests(t_utest *lst, t_utest *new)
{
	t_utest			*curr;

	curr = lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

static int			load_all(t_utest **test_loc)
{
	int				i;
	t_utest			*tmp;

	i = 0;
	while (launchers[i].name)
	{
		if (!(tmp = (*launchers[i].f)()))
			return (-1);
		if (*test_loc)
			add_tests(tmp, *test_loc);
		*test_loc = tmp;
		++i;
	}
	return (1);
}

int					load_tests(const char *name, t_utest **test_loc)
{
	int				i;
	t_utest			*tmp;

	if (!strcmp(name, "all"))
		return (load_all(test_loc));
	i = 0;
	while (launchers[i].name != NULL && strcmp(launchers[i].name, name))
		++i;
	if (!launchers[i].name)
		return (0);
	if (!(tmp = (*launchers[i].f)()))
		return (-1);
	if (*test_loc)
		add_tests(tmp, *test_loc);
	*test_loc = tmp;
	return (1);
}
