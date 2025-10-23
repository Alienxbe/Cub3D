/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 11:44:44 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PLAYER_FOV (M_PI / 3)

#include "sfe_pixel.h"
#include "player.h"
#include "raycast.h"
#include <stdio.h>

static t_ray	draw_ray(t_game *game, t_img *img, t_ray ray, int i)
{
	int		wall_height;
	t_point	wall_start;
	t_point	wall_end;
	t_point	window_bottom;
	t_point	window_top;
	float	corr;

	corr = cos (ray.angle - game->player.view_angle);
	ray = raycast(game, game->player.pos, ray, i);
	wall_height = (int)((WIN_HEIGHT / (ray.perp_dist * corr)));
	wall_start.y = (WIN_HEIGHT - wall_height) / 2;
	wall_end.y = wall_start.y + wall_height;
	wall_start.x = i;
	wall_end.x = i;
	window_bottom.x = i;
	window_bottom.y = 0;
	window_top.x = i;
	window_top.y = WIN_HEIGHT;

	sfe_draw_line(img, window_bottom, window_top , 0x0);
	sfe_draw_line(img, wall_start, wall_end, 0xFFF);
}

	// Ici, selon les infos de raycast on peut savoir quelle texture afficher.
	// ray.side == 0 && ray.step_x > 0 : WEST
	// ray.side == 0 && ray.step_x < 0 : EAST
	// ray.side == 1 && ray.step_y > 0 : NORTH
	// ray.side == 1 && ray.step_y < 0 : SOUTH

/* void	raycast_draw_2(t_game *game, t_img *img)
{
	t_ray		ray;
	float		cos_step;
	float		sin_step;
	int			i;
	float		old_x;

	i = 0;
	cos_step = cos(PLAYER_FOV / (float)WIN_WIDTH);
	sin_step = sin(PLAYER_FOV / (float)WIN_WIDTH);
	ray.dir.x = game->player.step.x * cos(-PLAYER_FOV / 2) - game->player.step.y * sin(-PLAYER_FOV / 2);
	ray.dir.y = game->player.step.x * sin(-PLAYER_FOV / 2) + game->player.step.y * cos(-PLAYER_FOV / 2);
	while (i <= WIN_WIDTH)
	{
		draw_ray(game, img, ray, i);
		old_x = ray.dir.x;
		ray.dir.x = old_x * cos_step - ray.dir.y * sin_step;
		ray.dir.y = old_x * sin_step + ray.dir.y * cos_step;
		i++;
	}
} */

void	raycast_draw(t_game *game, t_img *img)
{
	t_ray		ray;
	int			i;
	float		angle_step;

	angle_step = (PLAYER_FOV / (float)WIN_WIDTH);
	ray.angle = game->player.view_angle + (PLAYER_FOV/ 2);
	i = 0;
	while (i <= WIN_WIDTH)
	{
		ray.dir.x = cos(ray.angle);
		ray.dir.y = sin(ray.angle);
		draw_ray(game, img, ray, i);
		ray.angle -= angle_step;
		i++;
	}
}
