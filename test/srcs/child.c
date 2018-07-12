/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:59:48 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 12:50:52 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "test.h"

int					launch_child(t_utest *unit)
{
	if (!open_logfile(unit))
		return (0);
	else if ((unit->pid = fork()) == -1)
	{
		perror("fork() failed");
		return (0);
	}
	if (unit->pid == 0)
	{
		fprintf(g_logfile, "== %s ==\n", unit->name);
		exit((*unit->test)() ? EXIT_SUCCESS : EXIT_FAILURE);
	}
	return (1);
}

static inline void	chars_setback(int count)
{
	if (isatty(fileno(stdout)))
		while (--count > 0)
			putc('\b', stdout);
}

static inline void	chars_erase(int count)
{
	if (isatty(fileno(stdout)))
		while (--count > 0)
			putc(' ', stdout);
}

static inline void	chars_reset(int char_count)
{
	chars_setback(char_count);
	chars_erase(char_count);
	chars_setback(char_count + 1);
}

int					wait_for_child(pid_t pid, int *status, int uc)
{
	int				time;
	int				char_count;
	pid_t			ret;

	char_count = 0;
	usleep(1000);
	time = TIMEOUT_DELAY;
	while (time > 0)
	{
		chars_reset(char_count);
		if ((ret = waitpid(pid, status, WNOHANG)) == -1)
			return (0);
		else if (ret > 0)
			return (1);
		fputs(color(BLUE, uc), stdout);
		char_count = (time == TIMEOUT_DELAY || !uc ?
				0 : printf("(time: %d)", time));
		fputs(color(RESET, uc), stdout);
		fflush(stdout);
		sleep(1);
		--time;
	}
	chars_setback(char_count + 1);
	kill(pid, SIGKILL);
	return (2);
}
