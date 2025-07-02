/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:24:59 by cproust           #+#    #+#             */
/*   Updated: 2025/07/02 17:29:05 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	**copy_map_bzero(int **map, t_map m_data)
{
	int	**new_map;
	int	i;
	int	j;

	if (!map)
		return (NULL);
	new_map = malloc(sizeof(int *) * (m_data.size.y + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = malloc(sizeof(int) * m_data.size.x);
		if (!new_map[i])
		{
			free_arr((void **)new_map);
			return (NULL);
		}
		j = 0;
		while (j < m_data.size.x)
			new_map[i][j++] = 0;
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	flood_fill(int x, int y, int **visited, t_map map)
{
	int	tile;

	if (y < 0 || x < 0 || x >= map.size.x || y >= map.size.y)
		return (1);
	if (visited[y][x] == 1)
		return (0);
	tile = map.map[y][x];
	if (tile != 0 && tile != 1 && tile != 2 && \
		tile != 3 && tile != 4 && tile != 5)
		return (1);
	if (tile == 1)
		return (0);
	visited[y][x] = 1;
	if (flood_fill(x, y - 1, visited, map) == 1)
		return (1);
	if (flood_fill(x, y + 1, visited, map) == 1)
		return (1);
	if (flood_fill(x - 1, y, visited, map) == 1)
		return (1);
	if (flood_fill(x + 1, y, visited, map) == 1)
		return (1);
	return (0);
}

int	check_map(t_map map)
{
	int	**visited;

	visited = copy_map_bzero(map.map, map);
	if (flood_fill(map.player_pos.x, map.player_pos.y, visited, map) == 1)
		return (free_arr((void **)visited), 1);
	free_arr((void **)visited);
	return (0);
}
