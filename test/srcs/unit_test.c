/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:23:35 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 06:33:40 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "test.h"

void				del_unit_tests(t_utest **lst)
{
	t_utest			*curr;
	t_utest			*tmp;

	if (!lst || !*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr->next;
		free(curr->name);
		free(curr->launcher_name);
		free(curr);
		curr = tmp;
	}
	*lst = NULL;
}

static char			*my_strdup(const char *src)
{
	char			*str;
	size_t			len;

	if (!src)
		return (NULL);
	len = strlen(src);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	strcpy(str, src);
	return (str);
}

void				add_unit_test(void **lst, const char *dir_name,
		const char *name, int (*test)(void))
{
	t_utest			*u;

	if (!lst || !(u = malloc(sizeof(t_utest))))
	{
		del_unit_tests((t_utest **)lst);
		return ;
	}
	u->test = test;
	u->next = *((t_utest **)lst);
	u->pid = 0;
	(*lst) = (void *)u;
	if (!(u->name = my_strdup(name)))
		del_unit_tests((t_utest **)lst);
	else if (!(u->launcher_name = my_strdup(dir_name)))
		del_unit_tests((t_utest **)lst);
}
