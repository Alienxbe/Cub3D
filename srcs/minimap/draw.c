/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:41:52 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 16:38:21 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "player.h"
#include "raycast.h"
#include "minimap.h"

static void	draw_tile(t_game *game, t_img *img, t_point pos, t_color col)
{
	pos.x *= game->minimap.cell_size;
	pos.y *= game->minimap.cell_size;
	sfe_pixel_fill(img,
		(t_area){pos,
	{pos.x + game->minimap.cell_size, pos.y + game->minimap.cell_size}},
		col);
}

static void	draw_grid(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (i < game->map.size.y)
	{
		sfe_draw_line(img,
			(t_point){0, (i + 1) * game->minimap.cell_size},
			(t_point){game->minimap.cell_size * game->map.size.x,
			(i + 1) * game->minimap.cell_size}, 0x0);
		i++;
	}
	i = 0;
	while (i < game->map.size.x)
	{
		sfe_draw_line(img,
			(t_point){(i + 1) * game->minimap.cell_size, 0},
			(t_point){(i + 1) * game->minimap.cell_size,
			game->minimap.cell_size * game->map.size.y}, 0x0);
		i++;
	}
}

static void	draw_walls(t_game *game, t_img *img)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map.size.y)
	{
		x = 0;
		while (x < game->map.size.x && game->map.map[y][x] != TILE_TERM)
		{
			if (game->map.map[y][x] == TILE_WALL)
				draw_tile(game, img, (t_point){x, y}, MINIMAP_TILE_WALL_COLOR);
			else if (game->map.map[y][x] == TILE_FLOOR)
				draw_tile(game, img, (t_point){x, y}, MINIMAP_TILE_FLOOR_COLOR);
			x++;
		}
		y++;
	}
}

void	minimap_draw(t_game *game, t_img *img)
{
	if (!game->minimap.show)
		return ;
	draw_walls(game, img);
	draw_grid(game, img);
	player_draw(game, img);
	draw_rays(game, img);
}
