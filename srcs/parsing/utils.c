/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:20 by cproust           #+#    #+#             */
/*   Updated: 2025/10/24 15:50:42 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*remove_whitespace(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

t_bool	ft_str_is_empty(const char *str)
{
	if (!str || !*str)
		return (true);
	while (*str)
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}

void	free_arr(void ***arr_ptr)
{
	int	i;

	if (!arr_ptr || !*arr_ptr)
		return ;
	i = 0;
	while ((*arr_ptr)[i])
	{
		free((*arr_ptr)[i]);
		(*arr_ptr)[i] = NULL;
		i++;
	}
	free(*arr_ptr);
	*arr_ptr = NULL;
}

void	finish_gnl(int fd, char *line)
{
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	close(fd);
}
