/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:50:17 by marykman          #+#    #+#             */
/*   Updated: 2025/03/12 08:29:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "sc_main.h"
#include "cub3d.h"

void	draw_map(t_map map, t_point pos, t_point tile_size, t_img *img)
{
	t_color	grid_col = 0x00C0C0C0;

	sfe_pixel_fill(
		img,
		(t_area){pos, {pos.x + tile_size.x * map.size.x, pos.y + tile_size.y * map.size.y}},
		0x00FFFFFF
	);	// Draw background
	for (int y = 0; y < map.size.y; y++)
		for (int x = 0; x < map.size.x; x++)
			if (map.map[y][x])
				sfe_pixel_fill(
					img, 
					(t_area){
						{x * tile_size.x, y * tile_size.y},
						{(x + 1) * tile_size.x, (y + 1) * tile_size.y}
					}, 0x00008800); // Drawing case
	for (int y = 1; y <= map.size.y; y++)
		sfe_draw_line(img, (t_point){pos.x, pos.y + y * tile_size.y}, (t_point){pos.x + tile_size.x * map.size.x, pos.y + y * tile_size.y}, grid_col);
	for (int x = 1; x <= map.size.x; x++)
		sfe_draw_line(img, (t_point){pos.x + x * tile_size.x, pos.y}, (t_point){pos.x + x * tile_size.x, pos.y + tile_size.y * map.size.y}, grid_col);

}
