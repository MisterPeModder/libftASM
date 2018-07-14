/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 07:19:56 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 07:29:36 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tests.h"

int					ft_memdel_test(void)
{
	char			*m;

	m = malloc(42);
	puts("Deallocating pointer with ft_memdel():");
	ft_memdel((void **)&m);
	if (m)
	{
		puts(" - FAILURE: pointer was not set to NULL !");
		return (0);
	}
	puts(" - ok\npassing NULL to ft_memdel():");
	ft_memdel((void **)&m);
	if (m)
	{
		puts(" - FAILURE: pointer was set to non-NULL value !");
		return (0);
	}
	puts(" - ok");
	return (1);
}
