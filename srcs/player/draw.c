/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 11:49:52 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PLAYER_FOV (M_PI / 3)

#include "sfe_pixel.h"
#include "player.h"
#include <stdio.h>

static t_point	world_to_minimap(t_game *game, t_point p)
{
	double	scale;

	scale = (double)game->minimap.cell_size / CELL_SIZE;
	return ((t_point){p.x * scale, p.y * scale});
}

void	draw_vision(t_game *game, t_img *img, t_point player_pos)
{
	float	start_angle;
	float	end_angle;
	float	angle_step;
	float	current_angle;

	start_angle = game->player.view_angle - (PLAYER_FOV / 2);
	end_angle = game->player.view_angle + (PLAYER_FOV / 2);
	angle_step = PLAYER_FOV / (float)WIN_WIDTH;

	return ;
}


void	player_draw(t_game *game, t_img *img)
{
	t_point	pos;
	t_area	hitbox;

	pos = world_to_minimap(game, ft_fpoint_to_point(game->player.pos));
	hitbox.p1 = world_to_minimap(game, game->player.hitbox.p1);
	hitbox.p2 = world_to_minimap(game, game->player.hitbox.p2);
	sfe_pixel_fill(
		img,
		(t_area){
			add_point(pos, hitbox.p1),
			add_point(pos, hitbox.p2)
		}, PLAYER_MINIMAP_COLOR
	);
	draw_vision(game, img, pos);
}
