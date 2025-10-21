/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:29:59 by marykman          #+#    #+#             */
/*   Updated: 2025/10/21 18:37:40 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "player.h"
#include <stdio.h>

#define PLAYER_FOV (M_PI / 3)   // 60° field of view
#define RAY_COUNT 10           // 60 lines to draw

static t_point	world_to_minimap(t_game *game, t_point p)
{
	double	scale;

	scale = (double)game->minimap.cell_size / CELL_SIZE;
	return ((t_point){p.x * scale, p.y * scale});
}

static t_ray	dda_loop(t_game *game, t_ray ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray.c_dist_x < ray.c_dist_y)
		{
			ray.c_dist_x += ray.delta_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.c_dist_y += ray.delta_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (ray.map_x < 0 || ray.map_y < 0
			|| ray.map_x >= game->map.size.x
			|| ray.map_y >= game->map.size.y)
			break ;
		if (game->map.map[ray.map_y][ray.map_x] == TILE_WALL)
			hit = 1;
	}
	return (ray);
}

static t_ray	do_dda(t_game *game, t_ray ray, t_fpoint pos)
{
	int		c_s;

	c_s = CELL_SIZE;
	if (ray.dir.x == 0)
		ray.delta_x = 1e30;
	else
		ray.delta_x = fabs(1.0 / ray.dir.x);
	if (ray.dir.y == 0)
		ray.delta_y = 1e30;
	else
		ray.delta_y = fabs(1.0 / ray.dir.y);
	if (ray.step_x < 0)
		ray.c_dist_x = (pos.x - ray.map_x * c_s) / c_s * ray.delta_x;
	else
		ray.c_dist_x = ((ray.map_x + 1) * c_s - pos.x) / c_s * ray.delta_x;
	if (ray.step_y < 0)
		ray.c_dist_y = (pos.y - ray.map_y * c_s) / c_s * ray.delta_y;
	else
		ray.c_dist_y = ((ray.map_y + 1) * c_s - pos.y) / c_s * ray.delta_y;
	ray = dda_loop(game, ray);
	return (ray);
}

t_ray	raycast(t_game *game, t_fpoint dir, t_point player_pos)
{
	t_ray	ray;
	t_fpoint pos = { player_pos.x, player_pos.y };

	ray.dir = dir;
	ray.map_x = (int)(pos.x / CELL_SIZE);
	ray.map_y = (int)(pos.y / CELL_SIZE);

	if (dir.x < 0)
		ray.step_x = -1;
	else
		ray.step_x = 1;
	if (dir.y < 0)
		ray.step_y = -1;
	else
		ray.step_y = 1;
	ray = do_dda(game, ray, pos);
	if (ray.side == 0)
		ray.perp_dist = ray.c_dist_x - ray.delta_x;
	else
		ray.perp_dist = ray.c_dist_y - ray.delta_y;
	ray.hit.x = pos.x + ray.dir.x * ray.perp_dist * CELL_SIZE;
	ray.hit.y = pos.y + ray.dir.y * ray.perp_dist * CELL_SIZE;

	return (ray);
}

void	draw_ray(t_game *game, t_img *img, t_point player_pos, float angle)
{
	t_ray		ray;
	t_fpoint	dir;
	t_point		end;

	dir.x = cos(angle);
	dir.y = sin(angle);

	ray = raycast(game, dir, game->player.pos);
	end.x = ray.hit.x;
	end.y = ray.hit.y;

	sfe_draw_line(img, player_pos, world_to_minimap(game, end), 0x0);
}
