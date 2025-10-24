/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:52:03 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 12:54:10 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "player.h"

t_point	get_map_pos(t_map *map)
{
	t_point	i;

	i.y = 0;
	while (i.y < map->size.y)
	{
		i.x = 0;
		while (i.x < map->size.x && map->map[i.y][i.x] != TILE_TERM)
		{
			if (map->map[i.y][i.x] >= TILE_N && map->map[i.y][i.x] <= TILE_W)
				return (i);
			i.x++;
		}
		i.y++;
	}
	return (i);
}

float	get_view_angle(int tile)
{
	if (tile == TILE_N)
		return (3 * (M_PI / 2));
	else if (tile == TILE_S)
		return (M_PI / 2);
	else if (tile == TILE_E)
		return (M_PI);
	return (2* M_PI);
}

void	player_init(t_game *game)
{
	t_point	map_pos;

	map_pos = get_map_pos(&game->map);
	game->player.pos.x = map_pos.x * CELL_SIZE + CELL_SIZE / 2;
	game->player.pos.y = map_pos.y * CELL_SIZE + CELL_SIZE / 2;
	game->player.view_angle = get_view_angle(game->map.map[map_pos.y][map_pos.x]);
	game->player.step.x = cos(game->player.view_angle);
	game->player.step.y = sin(game->player.view_angle);
	game->map.map[map_pos.y][map_pos.x] = TILE_FLOOR;
	game->player.hitbox.p1 = (t_point){-10, -10};
	game->player.hitbox.p2 = (t_point){10, 10};
}