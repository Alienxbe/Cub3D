/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 16:51:34 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sfe_pixel.h"
#include "player.h"
#include "raycast.h"
#include <stdio.h>

static t_point	world_to_minimap(t_game *game, t_point p)
{
	double	scale;

	scale = (double)game->minimap.cell_size / CELL_SIZE;
	return ((t_point){p.x * scale, p.y * scale});
}

// static t_ray	draw_ray(t_game *game, t_img *img, t_ray ray, int i)
// {
// 	int		wall_height;
// 	t_point	wall_start;
// 	t_point	wall_end;
// 	t_point	window_bottom;
// 	t_point	window_top;
// 	float	corr;

// 	// wall_height = (int)((WIN_HEIGHT / (ray.perp_dist * corr)));
// 	// wall_start.y = (WIN_HEIGHT - wall_height) / 2;
// 	// wall_end.y = wall_start.y + wall_height;
// 	// wall_start.x = i;
// 	// wall_end.x = i;
// 	// window_bottom.x = i;
// 	// window_bottom.y = 0;
// 	// window_top.x = i;
// 	// window_top.y = WIN_HEIGHT;
// 	// game->rays[i] = ray;

// 	// sfe_draw_line(img, window_bottom, window_top , 0x0);
// 	// sfe_draw_line(img, wall_start, wall_end, 0xFFF);
// 	// sfe_draw_line(img,
// 	// 	world_to_minimap(game, ft_fpoint_to_point(game->player.pos)),
// 	// 	world_to_minimap(game, ray.hit),
// 	// 0x00FF00);
// 	// sfe_draw_line(img,
// 	// 	world_to_minimap(game, ft_fpoint_to_point(game->player.pos)),
// 	// 	world_to_minimap(game, add_point(ft_fpoint_to_point(game->player.pos), (t_point){ray.dir.x * 50, ray.dir.y * 50})),
// 	// 0x);
// }

	// Ici, selon les infos de raycast on peut savoir quelle texture afficher.
	// ray.side == 0 && ray.step_x > 0 : WEST
	// ray.side == 0 && ray.step_x < 0 : EAST
	// ray.side == 1 && ray.step_y > 0 : NORTH
	// ray.side == 1 && ray.step_y < 0 : SOUTH

void	draw_map_ray(t_game *game, t_img *img, t_ray *ray)
{
	sfe_draw_line(img,
		world_to_minimap(game, ft_fpoint_to_point(game->player.pos)),
		world_to_minimap(game, ft_fpoint_to_point(ray->hit)),
	0x00FF00);
	// sfe_draw_line(img,
	// 	world_to_minimap(game, ft_fpoint_to_point(game->player.pos)),
	// 	world_to_minimap(game, add_point(ft_fpoint_to_point(game->player.pos), (t_point){ray->dir.x * 50, ray->dir.y * 50})),
	// 0x0000ff);
}

static void	draw_walls(t_game *game, t_img *img, t_ray *ray)
{
	int		wall_height;
	t_point	wall_start;
	t_point	wall_end;

	wall_height = (int)((WIN_HEIGHT / (ray->length * ray->corr_angle)));
	if (wall_height > WIN_HEIGHT)
		wall_height = WIN_HEIGHT;
	wall_start.y = (WIN_HEIGHT - wall_height) / 2;
	wall_end.y = wall_start.y + wall_height;
	wall_start.x = ray - game->rays;
	wall_end.x = ray - game->rays;

	t_color	col;
	// ray.side == 0 && ray.step_x > 0 : WEST
	// ray.side == 0 && ray.step_x < 0 : EAST
	// ray.side == 1 && ray.step_y > 0 : NORTH
	// ray.side == 1 && ray.step_y < 0 : SOUTH
	if (ray->side == 0 && ray->step.x > 0)
		col = 0xFF0000;
	else if (ray->side == 0 && ray->step.x < 0)
		col = 0x00FF00;
	else if (ray->side == 1 && ray->step.y > 0)
		col = 0x0000FF;
	else if (ray->side == 1 && ray->step.y < 0)
		col = 0xFFFFFF;
	sfe_draw_line(img, wall_start, wall_end, col);
}

void	raycast_draw(t_game *game, t_img *img)
{
	size_t	i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		// draw_map_ray(game, img, game->rays + i);
		draw_walls(game, img, game->rays + i);
	}
}
