/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:44 by cproust           #+#    #+#             */
/*   Updated: 2025/10/24 12:29:24 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_tile(t_map *map, int i, int j)
{
	int		neighbors[4];
	int		k;

	if (i <= 0 || j <= 0 || i >= map->size.y - 1 || j >= map->size.x - 1)
		return (printf("Error\nMap not closed at tile %d, %d \n", i, j), 0);
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
			return (0);
		}
		k++;
	}
	return (1);
}

int	check_map_close(t_map *map)
{
	int	i;
	int	j;
	int	**mat;

	mat = map->map;
	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 8 || mat[i][j] == 2 || mat[i][j] == 3 \
				|| mat[i][j] == 4 || mat[i][j] == 5)
			{
				if (!check_tile(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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
		return (ft_printf("Error\nCould not open file '%s'\n", path), 0);
	while (get_next_line(fd, &line) > 0)
	{
		ret = parse_line(line, map, &line_counter);
		if (ret < 0)
		{
			close(fd);
			ft_printf("Failed to parse line '%s'\n", line);
			return (free(line), 0);
		}
		free(line);

	}
	free(line);
	if (close(fd) < 0)
		return (ft_printf("Error\nCould not close file '%s'\n", path), 0);
	return (1);
}

t_map	init_map(char *path)
{
	t_map	map;

	map = (t_map){0};
	map.player_pos.x = -1;
	map.player_pos.y = -1;
	map.player_dir = NORTH;
	if (!parse_file(path, &map))
		exit(1);
	if (!check_map_close(&map))
		exit(1);
	return (map);
}