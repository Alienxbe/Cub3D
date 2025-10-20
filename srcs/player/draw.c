/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/20 17:32:12 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "player.h"
#include <stdio.h>

static t_point	world_to_minimap(t_game *game, t_point p)
{
	double	scale;

	scale = (double)game->minimap.cell_size / CELL_SIZE;
	return ((t_point){p.x * scale, p.y * scale});
}

static void	draw_vision(t_game *game, t_img *img, t_point player_pos)
{
	t_point	end;

	end = ft_fpoint_to_point((t_fpoint){game->player.step.x * 40, game->player.step.y * 40});
	// printf("end: %d %d\n", end.x, end.y);
	sfe_draw_line(img,
		player_pos,
		add_point(player_pos, world_to_minimap(game, end)),
		0x0
	);
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
