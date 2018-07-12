/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:09:53 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 08:05:11 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>

typedef struct		s_utest
{
	char			*name;
	char			*launcher_name;
	int				(*test)(void);
	struct s_utest	*next;
	pid_t			pid;
}					t_utest;

struct				s_launcher
{
	const char		*name;
	void			*(*f)(void);
};

struct				s_core
{
	t_utest			*tests;
	int				use_colors;
};

void				add_unit_test(void **lst, const char *dir_name,
		const char *name, int (*test)(void));

void				del_unit_tests(t_utest **lst);

int					load_tests(const char *name, t_utest **test_loc);

int					launch_child(t_utest *unit);

int					wait_for_child(pid_t pid, int *status, int use_color);

int					get_args(int ac, char **av, struct s_core *core);

int					open_logfile(t_utest *unit);

enum				e_color
{
	RESET,
	BOLD,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	INVALID
};

const char			*color(enum e_color color, int use_color);

extern void			*g_logfile;

# define TIMEOUT_DELAY 5

#endif
