/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:29:59 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 17:07:35 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "raycast.h"

static void	init_steps(t_ray *ray)
{
	ray->step.x = 1;
	if (ray->dir.x < 0)
		ray->step.x = -1;
	ray->step.y = 1;
	if (ray->dir.y < 0)
		ray->step.y = -1;
}

static void	init_delta(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->delta.x = 1e10;
	else
		ray->delta.x = fabs(1.0 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta.y = 1e10;
	else
		ray->delta.y = fabs(1.0 / ray->dir.y);
}

static void	init_ray(t_ray *ray, t_fpoint player_pos)
{
	ray->map_pos.x = (int)(player_pos.x / CELL_SIZE);
	ray->map_pos.y = (int)(player_pos.y / CELL_SIZE);
	init_steps(ray);
	init_delta(ray);
}

void	raycast(t_game *game, t_ray *ray)
{
	init_ray(ray, game->player.pos);
	dda(game, ray);
	ray->length = ray->c_dist.x - ray->delta.x;
	if (ray->side)
		ray->length = ray->c_dist.y - ray->delta.y;
	ray->hit.x = game->player.pos.x + ray->dir.x * ray->length * CELL_SIZE;
	ray->hit.y = game->player.pos.y + ray->dir.y * ray->length * CELL_SIZE;
}
