/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:01:01 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 18:12:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static int	get_tile_type(const t_map *map, t_fpoint pos)
{
	t_point	p_map;

	p_map.x = pos.x / CELL_SIZE;
	p_map.y = pos.y / CELL_SIZE;
	return (map->map[p_map.y][p_map.x]);
}

t_bool	is_hitbox_colliding(t_map *map, t_area hitbox, t_fpoint pos)
{
	t_fpoint	points[4];
	int			i;
	int			collisions;

	points[0] = (t_fpoint){pos.x + hitbox.p1.x + 1,
		pos.y + hitbox.p1.y + 1};
	points[1] = (t_fpoint){pos.x + hitbox.p2.x - 1,
		pos.y + hitbox.p1.y + 1};
	points[2] = (t_fpoint){pos.x + hitbox.p2.x - 1,
		pos.y + hitbox.p2.y - 1};
	points[3] = (t_fpoint){pos.x + hitbox.p1.x + 1,
		pos.y + hitbox.p2.y - 1};
	collisions = 0;
	i = -1;
	while (++i < 4)
		if (get_tile_type(map, points[i]) == TILE_WALL)
			collisions |= (1 << i);
	return (collisions);
}

t_bool	player_is_solid(t_game *game, t_fpoint pos)
{
	return (is_hitbox_colliding(
			&game->map, game->player.hitbox, (t_fpoint)
			{game->player.pos.x + pos.x, game->player.pos.y + pos.y}));
}
