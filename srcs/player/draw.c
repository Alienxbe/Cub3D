/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/21 18:54:11 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PLAYER_FOV (M_PI / 3)
#define RAY_COUNT 120

#include "sfe_pixel.h"
#include "player.h"
#include <stdio.h>

static t_point	world_to_minimap(t_game *game, t_point p)
{
	double	scale;

	scale = (double)game->minimap.cell_size / CELL_SIZE;
	return ((t_point){p.x * scale, p.y * scale});
}

static void	draw_ray(t_game *game, t_img *img, t_point player_pos, float angle)
{
	t_ray		ray;
	t_fpoint	dir;
	t_point		end;

	dir.x = cos(angle);
	dir.y = sin(angle);

	ray = raycast(game, dir, game->player.pos);
	// Ici, selon les infos de raycast on peut savoir quelle texture afficher.
	// ray.side == 0 && ray.step_x > 0 : WEST
	// ray.side == 0 && ray.step_x < 0 : EAST
	// ray.side == 1 && ray.step_y > 0 : NORTH
	// ray.side == 1 && ray.step_y < 0 : SOUTH
	end.x = ray.hit.x;
	end.y = ray.hit.y;

	sfe_draw_line(img, player_pos, world_to_minimap(game, end), 0x0);
}

void	draw_vision(t_game *game, t_img *img, t_point player_pos)
{
	float	start_angle;
	float	end_angle;
	float	angle_step;
	float	current_angle;

	start_angle = game->player.view_angle - (PLAYER_FOV / 2);
	end_angle = game->player.view_angle + (PLAYER_FOV / 2);
	angle_step = PLAYER_FOV / (float)RAY_COUNT;

	current_angle = start_angle;
	while (current_angle <= end_angle)
	{
		draw_ray(game, img, player_pos, current_angle);
		current_angle += angle_step;
	}
}


void	player_draw(t_game *game, t_img *img)
{
	t_point	pos;
	t_area	hitbox;

	pos = world_to_minimap(game, game->player.pos);
	hitbox.p1 = world_to_minimap(game, game->player.hitbox.p1);
	hitbox.p2 = world_to_minimap(game, game->player.hitbox.p2);
	sfe_pixel_fill(
		img,
		(t_area){
			add_point(pos, hitbox.p1),
			add_point(pos, hitbox.p2)
		}, 0xFF0000
	);
	draw_vision(game, img, pos);
}
