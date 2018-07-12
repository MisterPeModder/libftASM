/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:39:17 by yguaye            #+#    #+#             */
/*   Updated: 2018/06/11 14:17:55 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static const char *g_colors[] =
{
	"\033[0m",
	"\033[1m",
	"\033[31m",
	"\033[32m",
	"\033[33m",
	"\033[34m",
	"\033[35m",
	""
};

const char			*color(enum e_color color, int use_color)
{
	if (use_color)
		return (g_colors[color > INVALID ? INVALID : color]);
	return (g_colors[INVALID]);
}
