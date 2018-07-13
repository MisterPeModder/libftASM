/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:45:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 01:42:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <libfts.h>

extern void			*g_logfile;

int					ft_bzero_test(void);
int					ft_isalnum_test(void);
int					ft_isalpha_test(void);
int					ft_isascii_test(void);
int					ft_isdigit_test(void);
int					ft_isprint_test(void);
int					ft_strcat_test(void);
int					ft_strlen_test(void);
int					ft_tolower_test(void);
int					ft_toupper_test(void);

#endif
