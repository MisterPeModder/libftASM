/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 06:22:29 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 03:44:35 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "test.h"

void				*g_logfile;

static int			safe_cp(char *dst, const char *src, int len)
{
	int				i;

	i = -1;
	while (++i < len && src[i])
	{
		if (src[i] == '/')
			dst[i++] = '\\';
		dst[i] = src[i];
	}
	dst[i] = 0;
	return (i);
}

static void			get_filenames(const char *dir, const char *file,
		char *out_dir, char *out_file)
{
	int				offset;

	strcpy(out_dir, "./logs/");
	offset = safe_cp(out_dir + 7, dir, 55) + 7;
	strcpy(out_file, out_dir);
	out_file[offset] = '/';
	offset += safe_cp(out_file + offset + 1, file, 58);
	strcpy(out_file + offset + 1, ".log");
}

static int			make_dirs(const char *dir)
{
	if (mkdir("./logs", 0755))
	{
		if (errno != EEXIST)
		{
			perror("couldn't make logs directory");
			return (0);
		}
		errno = 0;
	}
	if (mkdir(dir, 0755))
	{
		if (errno != EEXIST)
		{
			perror("couldn't make logs subdirectory");
			return (0);
		}
		errno = 0;
	}
	return (1);
}

int					open_logfile(t_utest *unit)
{
	char			dir[64];
	char			filename[128];

	if (g_logfile)
		fclose(g_logfile);
	if (!unit->name || !unit->launcher_name)
		return (0);
	get_filenames(unit->launcher_name, unit->name, dir, filename);
	if (!make_dirs(dir))
		return (0);
	if (!(g_logfile = fopen(filename, "w")))
	{
		perror("couldn't open log file");
		return (0);
	}
	return (1);
}
