/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:29:59 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 14:18:18 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "player.h"
#include <stdio.h>

void	dda_loop(t_game *game, t_ray *ray)
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

static void	dda(t_game *game, t_ray *ray)
{
	// Setup deltas
	if (ray->dir.x == 0)
		ray->delta.x = 1e10;
	else
		ray->delta.x = fabs(1.0 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta.y = 1e10;
	else
		ray->delta.y = fabs(1.0 / ray->dir.y);
	
	// Get distance before cell
	if (ray->step.x < 0)	// Left
		ray->c_dist.x = (game->player.pos.x - ray->map_pos.x * CELL_SIZE) / CELL_SIZE * ray->delta.x;
	else					// Right
		ray->c_dist.x = ((ray->map_pos.x + 1) * CELL_SIZE - game->player.pos.x) / CELL_SIZE * ray->delta.x;
	if (ray->step.y < 0)	// Up
		ray->c_dist.y = (game->player.pos.y - ray->map_pos.y * CELL_SIZE) / CELL_SIZE * ray->delta.y;
	else					// Down
		ray->c_dist.y = ((ray->map_pos.y + 1) * CELL_SIZE - game->player.pos.y) / CELL_SIZE * ray->delta.y;
	dda_loop(game, ray);
}

void	raycast(t_game *game, t_ray *ray)
{
	// Get map pos
	ray->map_pos.x = (int)(game->player.pos.x / CELL_SIZE);
	ray->map_pos.y = (int)(game->player.pos.y / CELL_SIZE);

	// Get steps
	ray->step.x = 1;
	if (ray->dir.x < 0)
		ray->step.x = -1;
	ray->step.y = 1;
	if (ray->dir.y < 0)
		ray->step.y = -1;

	dda(game, ray);

	if (ray->side == 0)
		ray->length = ray->c_dist.x - ray->delta.x;
	else
		ray->length = ray->c_dist.y - ray->delta.y;

	ray->hit.x = game->player.pos.x + ray->dir.x * ray->length * CELL_SIZE;
	ray->hit.y = game->player.pos.y + ray->dir.y * ray->length * CELL_SIZE;
}
