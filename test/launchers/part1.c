/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:24:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 20:38:34 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "launchers.h"
#include "tests/part1/tests.h"

void				*launcher_part1(void)
{
	void			*lst;

	lst = NULL;
	add_unit_test(&lst, "part1", "ft_toupper", &ft_toupper_test);
	add_unit_test(&lst, "part1", "ft_tolower", &ft_tolower_test);
	add_unit_test(&lst, "part1", "ft_strcat", &ft_strcat_test);
	add_unit_test(&lst, "part1", "ft_puts", &ft_puts_test);
	add_unit_test(&lst, "part1", "ft_isprint", &ft_isprint_test);
	add_unit_test(&lst, "part1", "ft_isdigit", &ft_isdigit_test);
	add_unit_test(&lst, "part1", "ft_isascii", &ft_isascii_test);
	add_unit_test(&lst, "part1", "ft_isalpha", &ft_isalpha_test);
	add_unit_test(&lst, "part1", "ft_isalnum", &ft_isalnum_test);
	add_unit_test(&lst, "part1", "ft_bzero", &ft_bzero_test);
	return (lst);
}
