/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:44 by cproust           #+#    #+#             */
/*   Updated: 2025/07/02 17:30:35 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void square_map(t_map *map)
{
	int	i;
	int	j;
	int	k;
	int	*new_line;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		k = -1;
		while (map->map[i][j] != TILE_TERM)
			j++;
		new_line = malloc(sizeof(int) * (map->size.x + 1));
		if (!new_line)
			return ;
		while (++k < j)
			new_line[k] = map->map[i][k];
		while (k < map->size.x)
			new_line[k++] = TILE_EMPTY;
		new_line[map->size.x] = TILE_TERM;
		free(map->map[i]);
		map->map[i] = new_line;
	}
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
		if (map->wall_text[i])
			ft_printf("Wall texture %d: %s\n", i, map->wall_text[i]);
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
	map.wall_text[NORTH] = NULL;
	map.wall_text[SOUTH] = NULL;
	map.wall_text[EAST] = NULL;
	map.wall_text[WEST] = NULL;
	if (path)
	{
		if (!parse_file(path, &map))
		{
			ft_printf("Error: Failed to parse file '%s'\n", path);
			exit(1);
		}
	}
	square_map(&map);
	print_map_struct(&map);
	return (map);
}