/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:00:47 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 17:33:10 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	dda_loop(t_game *game, t_ray *ray)
{
	while (true)
	{
		if (ray->c_dist.x < ray->c_dist.y)
		{
			ray->c_dist.x += ray->delta.x;
			ray->map_pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->c_dist.y += ray->delta.y;
			ray->map_pos.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map.map[ray->map_pos.y][ray->map_pos.x] == TILE_WALL)
			break ;
	}
}

void	dda(t_game *game, t_ray *ray)
{
	if (ray->step.x < 0)
		ray->c_dist.x = (game->player.pos.x - ray->map_pos.x * CELL_SIZE);
	else
		ray->c_dist.x = ((ray->map_pos.x + 1) * CELL_SIZE - game->player.pos.x);
	if (ray->step.y < 0)
		ray->c_dist.y = (game->player.pos.y - ray->map_pos.y * CELL_SIZE);
	else
		ray->c_dist.y = ((ray->map_pos.y + 1) * CELL_SIZE - game->player.pos.y);
	ray->c_dist.x = ray->c_dist.x / CELL_SIZE * ray->delta.x;
	ray->c_dist.y = ray->c_dist.y / CELL_SIZE * ray->delta.y;
	dda_loop(game, ray);
}
