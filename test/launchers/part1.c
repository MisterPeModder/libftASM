/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:24:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 06:31:10 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "launchers.h"
#include "tests/part1/tests.h"

void				*launcher_part1(void)
{
	void			*lst;

	lst = NULL;
	add_unit_test(&lst, "part1", "ft_strlen", &ft_strlen_test);
	return (lst);
}
