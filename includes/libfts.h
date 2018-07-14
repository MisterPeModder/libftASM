/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:34:53 by yguaye            #+#    #+#             */
/*   Updated: 2018/07/14 06:15:52 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <string.h>

void				ft_bzero(void *str, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_puts(const char *str);
char				*ft_strcat(char *dst, const char *src);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *str);

void				ft_cat(int fd);
void				ft_memdel(void **p);

#endif
