/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:24:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 08:55:02 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "launchers.h"
#include "tests/part1/tests.h"

void				*launcher_part1(void)
{
	void			*lst;

	lst = NULL;
	add_unit_test(&lst, "part1", "ft_isalnum", &ft_isalnum_test);
	add_unit_test(&lst, "part1", "ft_isalpha", &ft_isalpha_test);
	add_unit_test(&lst, "part1", "ft_isdigit", &ft_isdigit_test);
	add_unit_test(&lst, "part1", "ft_isprint", &ft_isprint_test);
	add_unit_test(&lst, "part1", "ft_strcat", &ft_strcat_test);
	add_unit_test(&lst, "part1", "ft_strlen", &ft_strlen_test);
	return (lst);
}
