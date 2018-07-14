/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:24:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 02:25:37 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "launchers.h"
#include "tests/part2/tests.h"

void				*launcher_part2(void)
{
	void			*lst;

	lst = NULL;
	add_unit_test(&lst, "part2", "ft_strlen", &ft_strlen_test);
	add_unit_test(&lst, "part2", "ft_memset", &ft_memset_test);
	add_unit_test(&lst, "part2", "ft_memcpy", &ft_memcpy_test);
	return (lst);
}
