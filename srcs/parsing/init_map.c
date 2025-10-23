/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:44 by cproust           #+#    #+#             */
/*   Updated: 2025/10/23 18:39:27 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_tile(t_map *map, int i, int j)
{
	int		neighbors[4];
	int		k;

	printf("%d\n", map->map[i][j]);
	if (i <= 0 || j <= 0 || i >= map->size.y - 1 || j >= map->size.x - 1)
		return (printf("Error\nMap not closed at tile %d, %d \n", i, j), -1);
	neighbors[0] = map->map[i+1][j];
	neighbors[1] = map->map[i-1][j];
	neighbors[2] = map->map[i][j-1];
	neighbors[3] = map->map[i][j+1];
	k = 0;
	while (k <= 3)
	{
		if (neighbors[k] == 6 || neighbors[k] == 7)
		{
			ft_printf("Error\nMap not closed at tile %d, %d \n", i, j);
			return (-1);
		}
		k++;
	}
	return (0);
}

int	check_map_close(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (map->map[i][j])
		{
			printf("%d, %d\n", i, j);
			if (map->map[i][j] == 8 || map->map[i][j] == 2 || map->map[i][j] == 3 \
				|| map->map[i][j] == 4 || map->map[i][j] == 5)
			{
				if (check_tile(map, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print_map_struct(t_map *map)
{
	ft_printf("Map size: %dx%d\n", map->size.x, map->size.y);
	ft_printf("Player position: (%d, %d)\n", map->player_pos.x, map->player_pos.y);
	ft_printf("Player direction: %d\n", map->player_dir);
	ft_printf("Ceiling color: %#010x\n", map->ceiling_col);
	ft_printf("Floor color: %#010x\n", map->floor_col);
	for (int i = 0; i < CARDINAL_MAX; i++)
	{
		if (map->wall_text_path[i])
			ft_printf("Wall texture %d: %s\n", i, map->wall_text_path[i]);
		else
			ft_printf("Wall texture %d: NULL\n", i);
	}
	for (int i = 0; i < map->size.y; i++)
	{
		if (map->map[i])
		{
			ft_printf("Map line %d: ", i);
			for (int j = 0; map->map[i][j] != 7; j++)
			{
				ft_printf("%d ", map->map[i][j]);
			}
			ft_printf("\n");
		}
		else
		{
			ft_printf("Map line %d: NULL\n", i);
		}
	}
}

static	int	parse_file(const char *path, t_map *map)
{
	int		line_counter;
	int		fd;
	char	*line;
	int		ret;

	line_counter = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Could not open file '%s'\n", path), 0);
	while (get_next_line(fd, &line) > 0)
	{
		ret = parse_line(line, map, &line_counter);
		if (ret < 0)
		{
			close(fd);
			ft_printf("Error: Failed to parse line '%s'\n", line);
			return (free(line), 0);
		}
		free(line);

	}
	free(line);
	if (close(fd) < 0)
		return (ft_printf("Error: Could not close file '%s'\n", path), 0);
	return (1);
}

t_map	init_map(char *path)
{
	t_map	map;

	map.map = NULL;
	map.size.x = 0;
	map.size.y = 0;
	map.player_pos.x = -1;
	map.player_pos.y = -1;
	map.player_dir = NORTH;
	map.ceiling_col = 0x00000000;
	map.floor_col = 0x00000000;
	map.wall_text_path[NORTH] = NULL;
	map.wall_text_path[SOUTH] = NULL;
	map.wall_text_path[EAST] = NULL;
	map.wall_text_path[WEST] = NULL;
	if (path)
	{
		if (!parse_file(path, &map))
		{
			ft_printf("Error\n Failed to parse file '%s'\n", path);
			exit(1);
		}
	}
	if (check_map_close(&map) == -1)
		exit(1);
	print_map_struct(&map);
	return (map);
}