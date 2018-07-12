/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:05:49 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/12 12:53:31 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "test.h"

static int			log_result(int status, int is_timeout)
{
	const char		*sig;
	int				ret;

	ret = 0;
	fputs("result: [", g_logfile);
	if (is_timeout)
		fputs("TIMEOUT", g_logfile);
	else if (WIFSIGNALED(status))
	{
		sig = strsignal(WTERMSIG(status));
		while (*sig)
		{
			putc(toupper(*sig), g_logfile);
			++sig;
		}
	}
	else if (WEXITSTATUS(status) == EXIT_SUCCESS && (ret = 1))
		fputs("OK", g_logfile);
	else
		fputs("KO", g_logfile);
	fputs("]\n", g_logfile);
	fflush(stdout);
	return (ret);
}

static int			handle_signals(int status, int is_timeout, int uc)
{
	const char		*sig;
	int				ret;

	ret = 0;
	fputs(color(BOLD, uc), stdout);
	if (is_timeout)
		printf("%s[TIMEOUT", color(BLUE, uc));
	else if (WIFSIGNALED(status))
	{
		printf("%s[", color(RED, uc));
		sig = strsignal(WTERMSIG(status));
		while (*sig)
		{
			putc(toupper(*sig), stdout);
			++sig;
		}
	}
	else if (WEXITSTATUS(status) == EXIT_SUCCESS && (ret = 1))
		printf("%s[OK", color(GREEN, uc));
	else
		printf("%s[KO", color(YELLOW, uc));
	printf("]%s\n", color(RESET, uc));
	fflush(stdout);
	return (log_result(status, is_timeout) && ret);
}

static int			split(t_utest *lst, int uc)
{
	t_utest			*curr;
	int				status;
	int				ret;
	int				len;
	int				score;

	curr = lst;
	len = 0;
	score = 0;
	while (curr)
	{
		if (!launch_child(curr))
			return (0);
		printf("%s (%s%lli%s): ", curr->name,
				color(MAGENTA, uc), (long long)curr->pid, color(RESET, uc));
		fflush(stdout);
		if (!(ret = wait_for_child(curr->pid, &status, uc)))
			return (0);
		score += handle_signals(status, (ret == 1 ? 0 : 1), uc);
		curr = curr->next;
		++len;
	}
	printf("Score: %d/%d\n", score, len);
	fflush(stdout);
	return (1);
}

static int			init_args(int ac, char **av, struct s_core *core)
{
	int				ret;

	if (!(ret = get_args(ac, av, core)))
		return (0);
	else if (ret > 1)
	{
		puts("Usage: unit [--help] [--no-colors] [--] <\"test1\" ...>");
		return (ret == 2 ? 0 : 2);
	}
	if (!core->tests)
	{
		fputs("No unit test specified\n", stderr);
		return (0);
	}
	return (1);
}

int					main(int ac, char **av)
{
	struct s_core	core;
	int				ret;

	core.tests = NULL;
	g_logfile = NULL;
	if (!(ret = init_args(ac, av, &core)) ||
			(ret != 2 && !split(core.tests, core.use_colors)))
	{
		if (g_logfile)
			fclose(g_logfile);
		del_unit_tests(&core.tests);
		return (EXIT_FAILURE);
	}
	if (g_logfile)
		fclose(g_logfile);
	del_unit_tests(&core.tests);
	return (EXIT_SUCCESS);
}
