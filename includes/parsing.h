/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:27:29 by cproust           #+#    #+#             */
/*   Updated: 2025/10/24 17:36:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# include "ft_colors.h"
# include "ft_point.h"
# include "ft_string.h"
# include "ft_printf.h"
# include "ft_memory.h"
# include "ft_bool.h"
# include "ft_ctype.h"



# ifndef OPT_NB
#  define OPT_NB 6
# endif

/* Parsing */
t_map	init_map(char *path);
int		parse_line(char *line, t_map *map, int *line_counter);
int		ft_realloc_map(char *line, t_map *map);

void	free_arr(void ***arr);
void	free_map(t_map map);

char	*remove_whitespace(char *str);
t_bool	ft_str_is_empty(const char *str);
void	finish_gnl(int fd, char *line);

#endif