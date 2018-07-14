/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:06:15 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 05:31:11 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHERS_H
# define LAUNCHERS_H

extern void			add_unit_test(void **lst, const char *dir_name,
		const char *name, int (*t)(void));

/*
** ADD YOUR LAUNCHERS BELOW:
**
** launchers functions should follow the following prototype:
**     void *my_launcher_name(void);
** you must then implement it and reference it in:
**     launchers/my_launcher_name.mk
** and a -include statement below the line 34 of the Makefile like this:
**     -include launchers/my_launcher_name.mk
** to load the launcher,
** add a line of the following format into srcs/launchers.c:
**     {"my_launcher_name", &my_launcher_name},
**
** Example launcher:
** void        example_launcher(void)
** {
**      void   *lst;
**
**      lst = NULL;
**      add_unit_test(&lst, "example_launcher", "test1", &test1);
**      return (lst);
** }
*/

void				*launcher_part1(void);
void				*launcher_part2(void);
void				*launcher_part3(void);

#endif
