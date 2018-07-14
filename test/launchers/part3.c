/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:24:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 07:17:52 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "launchers.h"
#include "tests/part3/tests.h"

void				*launcher_part3(void)
{
	void			*lst;

	lst = NULL;
	add_unit_test(&lst, "part3", "ft_memdel", &ft_memdel_test);
	add_unit_test(&lst, "part3", "ft_cat", &ft_cat_test);
	return (lst);
}
