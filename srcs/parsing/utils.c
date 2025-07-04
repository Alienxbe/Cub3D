/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:20 by cproust           #+#    #+#             */
/*   Updated: 2025/07/04 13:08:49 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	free_arr(void **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	char_to_tile(char c, int *tile)
{
	if (c == '1')
		*tile = TILE_WALL;
	else if (c == '0')
		*tile = TILE_FLOOR;
	else if (c == 'N')
		*tile = TILE_N;
	else if (c == 'S')
		*tile = TILE_S;
	else if (c == 'E')
		*tile = TILE_E;
	else if (c == 'W')
		*tile = TILE_W;
	else if (c == ' ' || c == '\t')
		*tile = TILE_EMPTY;
	else if (c == 'D')
		*tile = TILE_DOOR;
	else if (c == 'B')
		*tile = TILE_SPRITE;
}

static int	*line_to_int_arr(char *line, t_map *map)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * (ft_strlen(line) + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		if (ft_str_is_empty(line + i))
			break ;
		char_to_tile(line[i], &arr[i]);
		if (arr[i] == TILE_N || arr[i] == TILE_S \
			|| arr[i] == TILE_E || arr[i] == TILE_W)
		{
			if (map->player_pos.x != -1 || map->player_pos.y != -1)
				return (free(arr), ft_printf("Error: Multiple starts\n"), NULL);
			map->player_pos = (t_point){i, map->size.y};
			map->player_dir = arr[i] - TILE_N;
		}
	}
	return (arr[i] = TILE_TERM, arr);
}

int	ft_realloc_map(char *line, t_map *map)
{
	int		new_size;
	int		i;
	int		**new_map;

	if (!line || !map)
		return (0);
	new_size = map->size.y + 1;
	new_map = malloc(sizeof(int *) * (new_size + 1));
	if (!new_map)
		return (0);
	i = -1;
	while (++i < map->size.y)
		new_map[i] = map->map[i];
	new_map[i] = line_to_int_arr(line, map);
	if (!new_map[i])
		return (free(new_map), 0);
	new_map[new_size] = NULL;
	free(map->map);
	map->map = new_map;
	map->size.y = new_size;
	if (map->size.x < (int)ft_strlen(line))
		map->size.x = ft_strlen(line);
	return (1);
}
